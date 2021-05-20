class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        int len = arr.size();

        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                if (arr[i] * 2 == arr[j] && i != j)
                {
                    return true;
                }
            }
        }
        return false;
    }
};