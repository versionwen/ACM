
/*首先要枚举所有可能的配对情况，当完成所有虫洞的配对后，再检查有没有环，注意要将每次枚举求得的结果(1代表有环，0代表无环)累加并返回*/
#include<stdio.h>
#define MAX_WORMHOLES 12
int numOfWormholes;
int x[MAX_WORMHOLES + 1];
int y[MAX_WORMHOLES + 1];
//nextWormhole[current]表示虫洞current的X+方向上的第一个虫洞
int nextWormhole[MAX_WORMHOLES + 1];
//pare[wormhole]和虫洞wormhole配对的虫洞
int pare[MAX_WORMHOLES + 1];
int visited[MAX_WORMHOLES + 1];
int cycleExist(){
	int start;
	for (start = 1; start <= numOfWormholes; start++){
		//遍历每个虫洞为起点的情况
		int wormhole;
		for (wormhole = 1; wormhole <= numOfWormholes; wormhole++)
			visited[wormhole] = 0;
		visited[start] = 1;
 
		int current = start;
		while (1){
			//因为所有虫洞都是配对过的，所以先往配对的虫洞转移
			int next = pare[current];
			//注意：配对的虫洞间的穿梭不能标记为访问过，因为不同的穿梭方向路径不一样
			/*
			if (visited[next] == 1)
				return 1;
			visited[next] = 1;
			*/
 
			//再往X+方向的虫洞移动
			next = nextWormhole[next];
			if (next == 0)
				//X+方向没有虫洞，所以以start为起点没有环
				break;
 
			//注意:只有往X+方向移动后访问到的点才能标记为访问过
			if (visited[next] == 1)
				//循环访问，有环
				return 1;
			visited[next] = 1;
 
			current = next;
		}
	}
	//以各个虫洞为起点都不能产生环，所以这种配对的情况没有环
	return 0;
}
 
int cycleExistV1(){
	int start;
	for (start = 1; start <= numOfWormholes; start++){
		//遍历每个虫洞为起点的情况
		int current = start;
		//移动numOfWormholes次
		int move;
		for (move = 1; move <= numOfWormholes; move++)
			current = nextWormhole[ pare[current] ];
		if (current != 0)
		  //移动numOfWormholes次之后还能找到虫洞，说明以start为起点有环
			return 1;
	}
	//以各个虫洞为起点都不能产生环，所以这种配对的情况没有环
	return 0;
}
 
int formPair(){
	//先选定一个未配对的虫洞wormholeUnpared
	int wormholeUnpared = 0;
	int wormhole;
	for (wormhole = 1; wormhole <= numOfWormholes; wormhole++)
		if (pare[wormhole] == 0){
			wormholeUnpared = wormhole;
			break;
		}
 
	if (wormholeUnpared == 0)
		//所有虫洞都配对过，检查有无环
		if (cycleExist() == 1)
			return 1;
		else 
			return 0;
 
	int result = 0;
	int wormholetoConnect;
	//因为wormholeUnpared是第一个未配对的虫洞，所以其他未配对的虫洞在其后面
	for (wormholetoConnect = wormholeUnpared + 1; wormholetoConnect <= numOfWormholes; wormholetoConnect++)
		if (pare[wormholetoConnect]  == 0){
			//遍历其他未配对的虫洞并和wormholeUnpared连接
			pare[wormholeUnpared] = wormholetoConnect;
			pare[wormholetoConnect] = wormholeUnpared;
			//DFS枚举，并把每次枚举求得的结果累加起来
			result += formPair();
			pare[wormholeUnpared] = 0;
			pare[wormholetoConnect] = 0;
		}
 
	//要把每一次枚举求得的结果的累加返回
	return result;
}
 
 
int main(){
	freopen("input.txt", "r", stdin);
	scanf("%d", &numOfWormholes);
	int wormhole;
	for (wormhole = 1; wormhole <= numOfWormholes; wormhole++){
		scanf("%d %d", &x[wormhole], &y[wormhole]);
	}
 
	//计算nextWormhole[current]数组
	int current, next;
	for (current = 1; current <= numOfWormholes; current++)
		for (next = 1; next <= numOfWormholes; next++){
			if (y[current] != y[next] || x[next] <= x[current])
				//下个虫洞不在当前虫洞的X+方向
				continue;
			if (nextWormhole[current] == 0 || x[next] < x[ nextWormhole[current] ])
				//当前虫洞的X+方向的第一个虫洞还没确定或者找到X+方向上距离当前虫洞更近的虫洞
				nextWormhole[current] = next;
		}
	
	printf("%d\n", formPair());
	return 0;
}