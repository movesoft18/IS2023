#pragma once


struct LEResult
{
	double root; // ������ ���� ����
	int count;   // ���-�� ������ 0 - ���, 1-1������, 3 - ����������� ���������
};

LEResult LinearEquation(double a, double b);