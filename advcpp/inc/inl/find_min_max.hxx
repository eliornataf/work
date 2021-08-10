#ifndef FIND_MIN_MAX_CONTAINER_HXX
#define FIND_MIN_MAX_CONTAINER_HXX

template <typename FwdIter>
bool FindMinMaxInContainerIter(FwdIter a_beginIter, FwdIter a_endIter, typename FwdIter::value_type &a_minValue, typename FwdIter::value_type &a_maxValue)
{
    if (a_beginIter == a_endIter)
    {
        return false;
    }

    a_minValue = *a_beginIter;
    a_maxValue = *a_beginIter++;

    for (;a_beginIter < a_endIter;a_beginIter += 2) 
    {
        if ((a_beginIter + 1) < a_endIter) 
        {
            if (*a_beginIter < *(a_beginIter + 1))
            {
                if (*a_beginIter < a_minValue)
                {
                    a_minValue = *a_beginIter;
                }
                if (a_maxValue < *(a_beginIter + 1))
                {
                    a_maxValue = *(a_beginIter + 1);
                }
            }
            else 
            {
                if (*(a_beginIter + 1) < a_minValue)
                {
                    a_minValue = *(a_beginIter + 1);
                }
                if (a_maxValue < *a_beginIter)
                {
                    a_maxValue = *a_beginIter;
                }
            }
        }
        else
        {
            if (*a_beginIter < a_minValue)
            {
                a_minValue = *a_beginIter;
            }
            if (a_maxValue < *a_beginIter)
            {
                a_maxValue = *a_beginIter;
            }
        }
    }

    return true;
}

template <typename C>
bool FindMinMaxInContainer(C &a_container, typename C::value_type &a_minValue, typename C::value_type &a_maxValue) 
{
    return FindMinMaxInContainerIter(a_container.begin(), a_container.end(), a_minValue, a_maxValue);
}

#endif // FIND_MIN_MAX_CONTAINER_HXX
