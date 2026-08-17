#pragma once

class BusinessContext final
{
public:
    int run(int actionIndex, int uiBias, bool checked) const noexcept
    {
        const int checkedContribution = checked ? 97 : 0;
        return (((((actionIndex + 1) * 17) ^ (uiBias + actionIndex * 3))
                 + checkedContribution) % 1000003);
    }
};
