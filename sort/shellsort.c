/*************************************************************************
	> File Name: shellsort.c
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年03月27日 星期二 16时54分07秒
 ************************************************************************/

/*希尔排序*/
/*三个for 一个if*/
#include <stdio.h>

void ShellSort(int nums[], int numsSize)
{
    for(int gap = numsSize/2; gap > 0; gap /= 2)           //gap最小为1,所以>0
    {
        for(int i = gap; i < numsSize; i++)
        {
            for(int j = i-gap; j >= 0; j -= gap)           //-gap为了防止越界, >=0是要判断nums[0]与nums[0+gap]的大小关系
            {
                if(nums[j] > nums[j+gap])
                {
                    int temp = nums[j];
                    nums[j] = nums[j+gap];
                    nums[j+gap] = temp;
                }
            }
        }
    }
}


int main()
{
    int nums[] = {5,4,6,2,3,7,1,9,7,4};
    int numsSize = sizeof(nums)/sizeof(int);

    ShellSort(nums, numsSize);

    for(int i = 0; i < numsSize; i++)
    {
        printf("%d ", nums[i]);
    }

    return 0;
}
