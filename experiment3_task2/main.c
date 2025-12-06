#include <stdio.h>
#include<stdlib.h>

int maxDiff(int *nums, int left, int right);

int main(){
	int length;
	scanf("%d", &length);
	
	int *nums = (int*)malloc(length*sizeof(int));
	int i;
	for(i = 0; i < length; i++){
		scanf("%d", &nums[i]);
	}

	if(maxDiff(nums, 0, length - 1) >= 0){
		printf("true");
	}else{
		printf("false");
	}
	
	free(nums);
	
	return 0;
}

//玩家1的分差：玩家1-玩家2
//玩家2的分差：玩家2-玩家1 
//两者和为0 
int maxDiff(int *nums, int left, int right){
	int choose_left, choose_right;
	
	if(right == left){
		choose_left = nums[left];
		choose_right = nums[right];
	}else{
		choose_left = nums[left] - maxDiff(nums, left + 1, right);
		choose_right = nums[right] - maxDiff(nums, left, right - 1);
	}
	
	if(choose_left >= choose_right){
		return choose_left;
	}else{
		return choose_right;
	}
}
