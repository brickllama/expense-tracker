module; // Global Module Fragment

#include <string_view>

export module Core.ExpenseCategory; // Interface Unit

namespace Core
{
    constexpr std::string_view ENTERTAINMENT_SV = "Entertainment";
    constexpr std::string_view FOOD_SV = "Food";
    constexpr std::string_view MERCHANDISE_SV = "Merchandise";
    constexpr std::string_view MISCELLANEOUS_SV = "Miscellaneous";
    constexpr std::string_view RENT_SV = "Rent";
    constexpr std::string_view RESTAURANTS_SV = "Restaurants";
    constexpr std::string_view TRANSPORTATION_SV = "Transportation";
    constexpr std::string_view UTILITIES_SV = "Utilities";
    constexpr std::string_view OTHER_SV = "Other";

    export enum class ExpenseCategory
    {
        Entertainment,
        Food,
        Merchandise,
        Miscellaneous,
        Rent,
        Restaurants,
        Transportation,
        Utilities,
        Other
    };

    constexpr std::string_view ExpenseCategory_to_string_view(ExpenseCategory ec)
    {
        switch (ec)
        {
        case ExpenseCategory::Entertainment: return ENTERTAINMENT_SV;
        case ExpenseCategory::Food: return FOOD_SV;
        case ExpenseCategory::Merchandise: return MERCHANDISE_SV;
        case ExpenseCategory::Miscellaneous: return MISCELLANEOUS_SV;
        case ExpenseCategory::Rent: return RENT_SV;
        case ExpenseCategory::Restaurants: return RESTAURANTS_SV;
        case ExpenseCategory::Transportation: return TRANSPORTATION_SV;
        case ExpenseCategory::Utilities: return UTILITIES_SV;
        [[unlikely]] default: return OTHER_SV;
        }
    };
}
