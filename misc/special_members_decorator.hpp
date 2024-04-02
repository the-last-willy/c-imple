#pragma once

#include <iostream>

namespace cimp {

    template<typename Traits>
    class special_members_decorator : Traits::decorated_type {
    public:
        using decorated_type = typename Traits::decorated_type;

        special_members_decorator() {
            Traits::on_def_ctor();
        }

        template<typename... Args>
        special_members_decorator(Args&&... args)
            : decorated_type(std::forward<Args>(args)...)
        {
            Traits::on_val_ctor();
        }

        special_members_decorator(const special_members_decorator& other)
        : decorated_val(other.decorated_val)
        {
            Traits::on_cp_ctor();
        }

        ~special_members_decorator() {
            Traits::on_dtor();
        }

    private:
        decorated_type decorated_val;
    };

    template<typename DecoratedType>
    struct logging_special_members_traits {
        using decorated_type = DecoratedType;

        static void on_def_ctor() {
            std::cout << "def ctor" << std::endl;
        }

        static void on_val_ctor() {
            std::cout << "val ctor" << std::endl;
        }

        static void on_cp_ctor() {

        }

        static void on_mv_ctor() {

        }

        static void on_cp_asgn() {

        }

        static void on_mv_asgn() {

        }

        static void on_dtor() {
            std::cout << "dtor" << std::endl;
        }
    };

    template<typename Ty>
    using logging_special_members = special_members_decorator<logging_special_members_traits<Ty>>;
}