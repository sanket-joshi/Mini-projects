#include <iostream>
#include <vector>
#include <limits>
#include <ctime>
#include <cstdlib>

using namespace std;

typedef vector <int> ivec;

void MergeSort (ivec &nums);

ostream &operator << (ostream &stream, ivec obj)
{
    for (int i = 0;  i < obj.size(); i++)
        stream << obj [i] << " ";
    return stream;
}

int main()
{
    ivec nums;
    int MaxNums = 100;
    srand ((int)time(0));

    for (int i = 0; i < MaxNums; i++)
        nums.push_back(rand() % MaxNums);

    cout << " before sorting " << endl;
    cout << nums << endl;
    MergeSort(nums);
    cout << " after sorting " << endl;
    cout << nums << endl;

    return 0;
}

void MergeSortPartial(ivec &nums, int start, int end);
void Merge (ivec &nums, int start1, int start2, int end);

void MergeSort(ivec &nums)
{
    MergeSortPartial(nums, 0, (int)nums.size()-1);
}

void MergeSortPartial(ivec &nums, int start, int end)
{
    if (start < end)
    {
        int middle = (start + end)/2;
        MergeSortPartial(nums,start,middle);
        MergeSortPartial(nums,middle+1,end);
        Merge(nums,start,middle,end);
    }
}

void Merge (ivec &nums, int start1, int start2, int end)
{
    int length1, length2;
    int sentinel = numeric_limits <int> :: max();//

    length1 = start2-start1 + 1;
    length2 = end - start2;

    ivec left, right;

    for (int index = 0; index < length1; index ++)
    {
        int temp = nums [start1 + index];
        left.push_back(temp);
    }
    left.push_back(sentinel);
    start2++;

    for (int index = 0; index < length2; index++)
    {
        int temp = nums [start2 + index];
        right.push_back(temp);
    }
    right.push_back(sentinel);

    int LeftIndex = 0;
    int RightIndex = 0;

    for (int index = start1; index <= end; index++)
    {
        if (left[LeftIndex] <= right[RightIndex])
        {
            nums [index] = left [LeftIndex];
            LeftIndex++;
        }
        else
        {
            nums [index] = right [RightIndex];
            RightIndex++;

        }
    }
}
