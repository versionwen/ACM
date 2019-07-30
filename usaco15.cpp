
/*����Ҫö�����п��ܵ�����������������г涴����Ժ��ټ����û�л���ע��Ҫ��ÿ��ö����õĽ��(1�����л���0�����޻�)�ۼӲ�����*/
#include<stdio.h>
#define MAX_WORMHOLES 12
int numOfWormholes;
int x[MAX_WORMHOLES + 1];
int y[MAX_WORMHOLES + 1];
//nextWormhole[current]��ʾ�涴current��X+�����ϵĵ�һ���涴
int nextWormhole[MAX_WORMHOLES + 1];
//pare[wormhole]�ͳ涴wormhole��Եĳ涴
int pare[MAX_WORMHOLES + 1];
int visited[MAX_WORMHOLES + 1];
int cycleExist(){
	int start;
	for (start = 1; start <= numOfWormholes; start++){
		//����ÿ���涴Ϊ�������
		int wormhole;
		for (wormhole = 1; wormhole <= numOfWormholes; wormhole++)
			visited[wormhole] = 0;
		visited[start] = 1;
 
		int current = start;
		while (1){
			//��Ϊ���г涴������Թ��ģ�����������Եĳ涴ת��
			int next = pare[current];
			//ע�⣺��Եĳ涴��Ĵ����ܱ��Ϊ���ʹ�����Ϊ��ͬ�Ĵ�����·����һ��
			/*
			if (visited[next] == 1)
				return 1;
			visited[next] = 1;
			*/
 
			//����X+����ĳ涴�ƶ�
			next = nextWormhole[next];
			if (next == 0)
				//X+����û�г涴��������startΪ���û�л�
				break;
 
			//ע��:ֻ����X+�����ƶ�����ʵ��ĵ���ܱ��Ϊ���ʹ�
			if (visited[next] == 1)
				//ѭ�����ʣ��л�
				return 1;
			visited[next] = 1;
 
			current = next;
		}
	}
	//�Ը����涴Ϊ��㶼���ܲ�����������������Ե����û�л�
	return 0;
}
 
int cycleExistV1(){
	int start;
	for (start = 1; start <= numOfWormholes; start++){
		//����ÿ���涴Ϊ�������
		int current = start;
		//�ƶ�numOfWormholes��
		int move;
		for (move = 1; move <= numOfWormholes; move++)
			current = nextWormhole[ pare[current] ];
		if (current != 0)
		  //�ƶ�numOfWormholes��֮�����ҵ��涴��˵����startΪ����л�
			return 1;
	}
	//�Ը����涴Ϊ��㶼���ܲ�����������������Ե����û�л�
	return 0;
}
 
int formPair(){
	//��ѡ��һ��δ��Եĳ涴wormholeUnpared
	int wormholeUnpared = 0;
	int wormhole;
	for (wormhole = 1; wormhole <= numOfWormholes; wormhole++)
		if (pare[wormhole] == 0){
			wormholeUnpared = wormhole;
			break;
		}
 
	if (wormholeUnpared == 0)
		//���г涴����Թ���������޻�
		if (cycleExist() == 1)
			return 1;
		else 
			return 0;
 
	int result = 0;
	int wormholetoConnect;
	//��ΪwormholeUnpared�ǵ�һ��δ��Եĳ涴����������δ��Եĳ涴�������
	for (wormholetoConnect = wormholeUnpared + 1; wormholetoConnect <= numOfWormholes; wormholetoConnect++)
		if (pare[wormholetoConnect]  == 0){
			//��������δ��Եĳ涴����wormholeUnpared����
			pare[wormholeUnpared] = wormholetoConnect;
			pare[wormholetoConnect] = wormholeUnpared;
			//DFSö�٣�����ÿ��ö����õĽ���ۼ�����
			result += formPair();
			pare[wormholeUnpared] = 0;
			pare[wormholetoConnect] = 0;
		}
 
	//Ҫ��ÿһ��ö����õĽ�����ۼӷ���
	return result;
}
 
 
int main(){
	freopen("input.txt", "r", stdin);
	scanf("%d", &numOfWormholes);
	int wormhole;
	for (wormhole = 1; wormhole <= numOfWormholes; wormhole++){
		scanf("%d %d", &x[wormhole], &y[wormhole]);
	}
 
	//����nextWormhole[current]����
	int current, next;
	for (current = 1; current <= numOfWormholes; current++)
		for (next = 1; next <= numOfWormholes; next++){
			if (y[current] != y[next] || x[next] <= x[current])
				//�¸��涴���ڵ�ǰ�涴��X+����
				continue;
			if (nextWormhole[current] == 0 || x[next] < x[ nextWormhole[current] ])
				//��ǰ�涴��X+����ĵ�һ���涴��ûȷ�������ҵ�X+�����Ͼ��뵱ǰ�涴�����ĳ涴
				nextWormhole[current] = next;
		}
	
	printf("%d\n", formPair());
	return 0;
}