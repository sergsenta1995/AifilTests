#include "stdafx.h"

using namespace std;

char *optarg = nullptr;
int optind = 1;
using namespace std;

// ������ 3
// �������� ������� ���������� ������� ��� ������� ���������� ��������� ������(getopt).
// ��������, ��� ��� ��������� ��������� ������, ���������� ������� ��������� ����������
// ����� ���������� ���������� ���� - ������, �����, ����� � ��������� ������ � �.�., 
// � ����� �������, �������� �� ���� �������� ������������.
// ��������, ��� ��������� ����� ������������ ������ � "�������" ������� � ������������ "--" 
// ����� ������ ���������(�� ���� "--my-option-name my-option-val", "--my-option-name=my-option-val", "--my-boolean-option").
// ���������� ����� ���� ���������.
// ������� ������ ����������� ����� ������������ �������� "--help" 
// (���� �� ������ � ������ ���������� ��� ������ �������), ��������� ������ �������������
// (�������������� ��������� ������ ���������� � ���������� �������).

namespace Question3
{
	const int NO_ARGUMENT = 0;
	const int REGUIRED_ARGUMENT = 1;

	struct SParameter {
		const char *name;
		int has_argument; // NO_ARGUMENT       = 0;
		                  // REGUIRED_ARGUMENT = 1;
		char result_sign;
	};


	int getopt(
		int argc,
		char * const argv[],
		const SParameter parameters[],
		const int parameters_size,
		int &index)
	{
		optarg = "(null)";

		// ������ � ����������� ���������.
		if (argc == index)
			return -1;

		// ����� "--help"
		if (strcmp(argv[index], "--help") == 0)
		{
			cout << "\nHelp for comand parameters." << endl;
			cout << "Example program call:" << endl;
			cout << "  main.exe --run 100 --size=80" << endl;
			cout << "List parameters:" << endl;
			for (int i = 0; i < parameters_size; i++)
			{
				cout << "  " << parameters[i].name;
				if (parameters[i].has_argument == NO_ARGUMENT)
					cout << "=argument" << endl;
				else
					cout << "=[argument]" << endl;
			}
		}

		// ���� ���������� �������� ��������� ������ � ������� ���������� ����������.
		for (int i = 0; i < parameters_size; i++)
		{
			// �������� ������ �� ����� "="
			// �������� ������ ��� �������� ����������
			char copy_argv[200];
			strcpy_s(copy_argv, 200, argv[index]);
			char *context = nullptr;
			// �������� �� ����� "="
			char const * splited_by_eqal = strtok_s(copy_argv, "=", &context);

			if (strcmp(splited_by_eqal, parameters[i].name) == 0)
			{
				// ���� ������ ����������� c ������jv (�. �. "=" �������)
				if (strcmp(context, "\0") != 0)
				{
					optarg = new char();
					strcpy_s(optarg, 200, context);
					return parameters[index++].result_sign;
				}

				if (parameters[i].has_argument == REGUIRED_ARGUMENT &&
					index + 1 <= argc)
				{
					optarg = argv[index + 1];
				}
			}
		}
		return parameters[index++].result_sign;
	}

	void PrintExample(int argc, char * argv[])
	{
		const struct Question3::SParameter parameters[] = {
			{ "--help", Question3::NO_ARGUMENT, 'h' },
			{ "--size", Question3::REGUIRED_ARGUMENT, 's' }
		};

		int parameters_size = sizeof(parameters) / sizeof(Question3::SParameter);

		char rez;
		int index = 1;
		while ((rez = Question3::getopt(argc, argv, parameters, parameters_size, index)) != -1){
			switch (rez){
			case 'h': cout << "Found argument '--help'; argument " << optarg; break;
			case 's': cout << "Found argument '--size'; argument " << optarg; break;
			}
		}
	}
}
