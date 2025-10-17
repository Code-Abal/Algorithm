#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>
using namespace std;

struct Car
{
	int hour, minute, carNum;
	int parking_Fee = 0;

	Car() : hour(-1), minute(-1), carNum(-1) {}
	Car(int _hour, int _minute, int _carNum) :
		hour(_hour), minute(_minute), carNum(_carNum) {}
};

map<int, Car> carMap;
map<int, int> ansMap;

vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> answer;

	int baseTime = fees[0];
	int baseFee = fees[1];
	int timePerUnit = fees[2];
	int feePerUnit = fees[3];

	for (int i = 0; i < records.size(); i++)
	{
		int hour = stoi(records[i].substr(0, 2));
		int minute = stoi(records[i].substr(3, 2));
		int carNum = stoi(records[i].substr(6, 4));
		string state = records[i].substr(11, records[i].length());
		bool parking = false;
		if (state == "IN")
		{
			Car car = Car(hour, minute, carNum);
			carMap[carNum] = car;
		}
		else // OUT
		{
			int start_Parking = carMap[carNum].hour * 60 + carMap[carNum].minute;
			int end_Parking = hour * 60 + minute;
			int time_Parking = end_Parking - start_Parking; // 총 주차시간

			ansMap[carNum] += time_Parking;
			carMap.erase(carNum);

			//cout << "차량번호 : " << carNum << " 누적 주차 시간 : " << ansMap[carNum] << "\n";
		}
	}
	//ceil((double)time_Parking / timePerUnit) * feePerUnit;
	// 여기까지 정상작동 됐으면, carMap에 남은 건 출차하지 않은 차량들.
	for (auto car : carMap)
	{
		int carNum = car.second.carNum;

		int start_Parking = carMap[carNum].hour * 60 + carMap[carNum].minute;
		int end_Parking = 23 * 60 + 59;
		int time_Parking = end_Parking - start_Parking; // 총 주차시간

		ansMap[carNum] += time_Parking;

		//cout << "차량번호 : " << carNum << " 누적 주차 시간 : " << ansMap[carNum] << "\n";
	}

	for (auto a : ansMap)
	{
		int totalParkingTime = a.second;
		if (totalParkingTime <= baseTime) answer.push_back(baseFee);
		else
		{
			int parkingFee = baseFee;
			totalParkingTime -= baseTime;
			parkingFee += ceil((double)totalParkingTime / timePerUnit) * feePerUnit;
			answer.push_back(parkingFee);
		}
	}
	return answer;
}