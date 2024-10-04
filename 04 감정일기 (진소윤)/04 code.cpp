#include <iostream>
#include<string>
#include<fstream>
#include<windows.h>
#include <ctime>

using namespace std;

string user = ""; // 현재 로그인된 아이디
string diary;

void login() {
	int num=0;
	string diary_read[100];

	while (1) {
		cout << "원하는 서비스의 숫자를 입력하세요" << endl;
		cout << endl;
		cout << "--- 1. 일기 작성하기   2. 작성한 일기 확인하기   3. 로그아웃하기 ---" << endl;
		cout << endl;
		cout << "원하는 서비스의 숫자를 입력하세요" << endl;
		cout << "숫자를 입력하세요 :";
		cin >> num;

		if (num == 1) {
			cout << "일기 작성을 시작합니다!" << endl;
			cout << "." << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "일기를 작성하세요! " << endl;
			cout << endl;
			cout << "-- 일기 작성을 마치려면 '*'을 작성해주세요 --" << endl;
			getline(cin, diary, '*');

			ofstream fout;
			fout.open("./diary/" + user + ".txt", ios::out | ios::app);
			fout << diary << "\n-\n";
			fout.close();

		}
		else if (num == 2) {
			string diary_read;
			ifstream fin("./diary/" + user + ".txt");
			if (!fin.is_open()) {
				cout << "파일 열기를 실패하였습니다. 다시 시도해 주세요.";
				system("cls");
			}cout << "." << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);

			cout << "작성한 일기를 열람하세요 ( // ^_^ // )" << endl;
			cout << endl;
			cout << endl;
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);

			while (1) {
				if (fin.eof()) {
					break;
				}
				getline(fin, diary_read);
				cout << diary_read << endl;
				cout << ".";
				Sleep(1000);
				cout << ".";
				Sleep(1000);
				cout << ".";
				Sleep(1000);

			}

			fin.close();
		}
		else if (num == 3) {
			cout << "enter 키를 누르세요.";
			return; //void에서도 숫자를 뒤에 쓰지 않으면  return을 쓸 수 있다. return 뒤에 숫자를 쓰지 않으면 처음으로 돌아가게 되고,main에서 return 0으로 프로그램이 종료된다.
		}
	}
}

int main() {

	int num;

	while (1) {

		cout << "                              __                                           __                                        \n";
		cout << "                             /\\ \\__    __                                 /\\ \\     __                                \n";
		cout << "   __     ___ ___      ___   \\ \\ ,_\\  /\\_\\     ___     ___                \\_\\ \\   /\\_\\      __      _ __   __  __    \n";
		cout << " /'__`\\ /' __` __`\\   / __`\\  \\ \\ \\/  \\/\\ \\   / __`\\ /' _ `\\              /'_` \\  \\/\\ \\   /'__`\\   /\\`'__\\/\\ \\/\\ \\   \n";
		cout << "/\\  __/ /\\ \\ /\\ \\ /\\ /\\ \\L\\ \\  \\ \\ \\_  \\ \\ \\ /\\ \\L\\ \\/\\ \\/\\ \\            /\\ \\L\\ \\  \\ \\ \\ /\\ \\L\\.\\_ \\ \\ \\/ \\ \\ \\_\\ \\  \n";
		cout << "\\ \\____/\\ \\_\\ \\_\\ \\_\\\\ \\____/   \\ \\__\\  \\ \\_\\\\ \\____/\\ \\_\\ \\_\\           \\ \\___,_\\  \\ \\_\\\\ \\__/.\\_\\ \\_\\ \\  \\/`____ \\ \n";
		cout << " \\/___/ \\/_/ \\/_/ \\/_/\\/___/     \\/__/   \\/_/ \\/___/  \\/_/\\/_/            \\/__,_ /   \\/_/ \\/__/\\/_/  \\/_/   `/___/> \\ \n";
		cout << "                                                                                                               /\\___/  \n";
		cout << "                                                                                                               \\/__/  \n";
		cout << endl;
		cout << " (^o^) -- 감정 일기 프로그램을 시작합니다 -- (^o^) ";

		cout << " " << endl;
		cout << " " << endl;
		cout << " " << endl;
		cout << " - 회원가입 및 로그인 - " << endl;
		cout << endl;
		cout << endl;
		cout << "* 아직 계정이 없다면 회원가입을 위해 숫자 1을 입력해주세요 (^.^) * " << endl;
		cout << "숫자를 입력하시오: 1. 회원가입 2. 로그인 3. 프로그램 종료" << endl;
		cout << "숫자 입력 :";
		cin >> num;
		if (num == 3) {
			break;
		}
		else if (num == 1) {
			string pw;
			string id;

			ofstream fout("idpw.txt", ios::out | ios::app);
			if (!fout) {
				cout << "파일열기 실패" << endl;
				return -1;
			}

			cout << endl;
			cout << "회원 가입을 시작합니다." << endl;
			cout << endl;
			cout << "아이디를 입력하세요 ^_^" << endl;
			cout << "ID:";
			cin >> id;
			cout << "비밀번호를 입력하세요" << endl;
			cout << "PW:";
			cin >> pw;
			fout << id;
			fout << " ";
			fout << pw;
			fout << "\n";

			fout.close();

			fout.open("./diary/" + id + ".txt");
			fout.close();

			cout << "회원가입이 완료되었습니다." << endl;
		}
		else if (num == 2) {
			string repw, reid;
			string fpw, fid;

			ifstream fin("idpw.txt");
			if (!fin) {
				cout << "파일 열기 실패" << endl;
				return -1;
			}
			cout << endl;
			cout << "로그인을 시작합니다." << endl;
			cout << endl;
			cout << "아이디를 입력하세요" << endl;
			cin >> reid;
			cout << "비밀번호를 입력하세요" << endl;
			cin >> repw;

			while (1) {
				if (fin.eof())
					break;
				fin >> fid >> fpw;
				if (reid == fid && repw == fpw) {
					cout << "로그인에 성공하였습니다!" << endl;
					cout << endl;
					user = fid;
					cout << "." << endl;
					Sleep(1000);
					cout << "." << endl;
					Sleep(1000);
					cout << "." << endl;
					Sleep(1000);
					login();
					cout << "로그아웃 되었습니다!" << endl;
					user = "";
					break;
				}
			}
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			system("cls");
			fin.close();
		}
		
	}


	return 0;
}