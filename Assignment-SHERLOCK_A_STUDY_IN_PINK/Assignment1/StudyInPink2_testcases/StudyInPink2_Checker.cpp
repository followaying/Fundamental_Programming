#include "C:\\Users\\VOSTRO 3490\\OneDrive\\Desktop\\BTL1\\studyInPink2.h" //Change this directory to the location of your studyInPink2.h
																		   // Use / or \\ for directory
using namespace std;

//Download the .rar file and extract it somewhere (for example your Desktop) and save its directory
//We wil use this directory later
const string directory = "C:\\Users\\VOSTRO 3490\\OneDrive\\Desktop\\Test\\StudyInPink2_testcases"; //Change this 
//(for example: If your StudyInPink2_testcases folder is in E:\StudyInPink2_testcases then change this to "E:\\StudyInPink2_testcases"

//DO NOT MODIFY ANY FUNCTION HERE, YOU DON'T NEED TO INCLUDE ANY OTHER LIBRARIES

void set_count(int& count)
{
	count = 0;
}

bool check_ntb1(int test)
{
	string ntb1 = directory + "\\notebook1\\input\\input" + to_string(test) + "\\NTB1_" + to_string(test) + "INP.txt";
	string output = directory + "\\notebook1\\output\\output" + to_string(test) + "\\NTB1_" + to_string(test) + "OUT.txt";
	ifstream inp(output);
	string ans;
	inp >> ans;
	string pwd1 = notebook1(ntb1);
	cout << "Testcase #" << test << ": " << endl;
	cout << "Your answer: " << pwd1 << endl;
	cout << "Expected result: " << ans << endl;
	cout << (pwd1 == ans ? "Correct!" : "Wrong answer!") << endl;
	if (pwd1 == ans)
	{
		return true;
	}
	return false;
}

bool check_ntb2(int test)
{
	string ntb2 = directory + "\\notebook2\\input\\input" + to_string(test) + "\\NTB2_" + to_string(test) + "INP.txt";
	string output = directory + "\\notebook2\\output\\output" + to_string(test) + "\\NTB2_" + to_string(test) + "OUT.txt";
	ifstream inp(output);
	string ans;
	inp >> ans;
	string pwd2 = notebook2(ntb2);
	cout << "Testcase #" << test << ": " << endl;
	cout << "Your answer: " << pwd2 << endl;
	cout << "Expected result: " << ans << endl;
	cout << (pwd2 == ans ? "Correct!" : "Wrong answer!") << endl;
	if (pwd2 == ans)
	{
		return true;
	}
	return false;
}

bool check_ntb3(int test)
{
	string ntb3 = directory + "\\notebook3\\input\\input" + to_string(test) + "\\NTB3_" + to_string(test) + "INP.txt";
	string output = directory + "\\notebook3\\output\\output" + to_string(test) + "\\NTB3_" + to_string(test) + "OUT.txt";
	ifstream inp(output);
	string ans;
	inp >> ans;
	string pwd3 = notebook3(ntb3);
	cout << "Testcase #" << test << ": " << endl;
	cout << "Your answer: " << pwd3 << endl;
	cout << "Expected result: " << ans << endl;
	cout << (pwd3 == ans ? "Correct!" : "Wrong answer!") << endl;
	if (pwd3 == ans)
	{
		return true;
	}
	return false;
}

bool check_GenerateListPasswords(int test)
{
	string ntb1 = directory + "\\notebook1\\input\\input" + to_string(test) + "\\NTB1_" + to_string(test) + "INP.txt";
	string ntb2 = directory + "\\notebook2\\input\\input" + to_string(test) + "\\NTB2_" + to_string(test) + "INP.txt";
	string ntb3 = directory + "\\notebook3\\input\\input" + to_string(test) + "\\NTB3_" + to_string(test) + "INP.txt";
	string output = directory + "\\generatePass\\output\\output" + to_string(test) + "\\generatePass_" + to_string(test) + "OUT.txt";
	ifstream inp(output);
	string ans;
	inp >> ans;
	string pwd1 = notebook1(ntb1);
	string pwd2 = notebook2(ntb2);
	string pwd3 = notebook3(ntb3);
	string result = generateListPasswords(pwd1, pwd2, pwd3);
	cout << "Testcase #" << test << ": " << endl;
	cout << "Your answer: " << result << endl;
	cout << "Expected result: " << ans << endl;
	cout << (result == ans ? "Correct!" : "Wrong answer!") << endl;
	if (result == ans)
	{
		return true;
	}
	return false;
}

bool check_chaseTaxi(int test)
{
	string input = directory + "\\chaseTaxi\\input\\input" + to_string(test) + "\\chaseTaxi_" + to_string(test) + "INP.txt";
	string output = directory + "\\chaseTaxi\\output\\output" + to_string(test) + "\\chaseTaxi_" + to_string(test) + "OUT.txt";
	ifstream inp(input);
	ifstream out(output);
	string moves, points, outTimes, outCatchUps;
	string res1, res2, res3, ans1, ans2, ans3;
	getline(inp, moves);
	getline(inp, points);
	getline(out, ans1);
	getline(out, ans2);
	getline(out, ans3);
	int arr[100][100];
	bool reach = chaseTaxi(arr, points, moves, outTimes, outCatchUps);
	res1 = "Can reach: " + to_string(reach);
	res2 = "outTimes: " + outTimes;
	res3 = "outCatchUps: " + outCatchUps;
	cout << "Testcase #" << test << ": " << endl;
	cout << "Your answer: " << endl;
	cout << res1 << endl;
	cout << res2 << endl;
	cout << res3 << endl;
	cout << "Expected result: " << endl;
	cout << ans1 << endl;
	cout << ans2 << endl;
	cout << ans3 << endl;
	if (res1 == ans1 && res2 == ans2 && res3 == ans3)
	{
		cout << "Correct!" << endl;
		return true;
	}
	cout << "Wrong answer!" << endl;
	return false;
}

bool check_Enterlaptop(int test)
{
	string tag = directory + "\\enterLaptop\\input\\input" + to_string(test) + "\\enterLaptop_tag" + to_string(test) + "INP.txt";
	string message = directory + "\\enterLaptop\\input\\input" + to_string(test) + "\\enterLaptop_message" + to_string(test) + "INP.txt";
	string output = directory + "\\enterLaptop\\output\\output" + to_string(test) + "\\enterLaptop_" + to_string(test) + "OUT.txt";
	string msg, loginInfo, ans;
	ifstream inp1(message);
	ifstream inp2(output);
	inp1 >> msg;
	inp2 >> ans;
	loginInfo = enterLaptop(tag, msg);
	cout << "Testcase #" << test << ": " << endl;
	cout << "Your answer: " << loginInfo << endl;
	cout << "Expected result: " << ans << endl;
	if (loginInfo == ans)
	{
		cout << "Correct!" << endl;
		return true;
	}
	cout << "Wrong answer!" << endl;
	return false;
}

int main()
{
	//IF YOU WANT TO CHECK FOR ANY TASKS, LEAVE THE TASKS YOU CHOOSE AND COMMENT THE REST
	//notebook1
	int count = 0;
	cout << "Task notebook1: " << endl;
	for (int i = 1; i <= 100; i++)
	{
		if (check_ntb1(i) == false)
		{
			break;
		}
		else
		{
			count++;
		}
	}
	if (count < 100)
	{
		cout << "Your code failed one or more hidden tests";
		return 0;
	}

	//notebook2
	set_count(count);
	cout << "Task notebook2: " << endl;
	for (int i = 1; i <= 100; i++)
	{
		if (check_ntb2(i) == false)
		{
			break;
		}
		else
		{
			count++;
		}
	}
	if (count < 100)
	{
		cout << "Your code failed one or more hidden tests";
		return 0;
	}

	//notebook3
	set_count(count);
	cout << "Task notebook3: " << endl;
	for (int i = 1; i <= 100; i++)
	{
		if (check_ntb3(i) == false)
		{
			break;
		}
		else
		{
			count++;
		}
	}
	if (count < 100)
	{
		cout << "Your code failed one or more hidden tests";
		return 0;
	}

	//GenerateListPasswords
	set_count(count);
	cout << "Task GenerateListPasswords: " << endl;
	for (int i = 1; i <= 100; i++)
	{
		if (check_GenerateListPasswords(i) == false)
		{
			break;
		}
		else
		{
			count++;
		}
	}
	if (count < 100)
	{
		cout << "Your code failed one or more hidden tests";
		return 0;
	}

	//chaseTaxi
	set_count(count);
	cout << "Task chaseTaxi: " << endl;
	for (int i = 1; i <= 100; i++)
	{
		if (check_chaseTaxi(i) == false)
		{
			break;
		}
		else
		{
			count++;
		}
	}
	if (count < 100)
	{
		cout << "Your code failed one or more hidden tests";
		return 0;
	}

	//enterLaptop
	set_count(count);
	cout << "Task enterLaptop: " << endl;
	for (int i = 1; i <= 100; i++)
	{
		if (check_Enterlaptop(i) == false)
		{
			break;
		}
		else
		{
			count++;
		}
	}
	if (count < 100)
	{
		cout << "Your code failed one or more hidden tests";
		return 0;
	}
}
