
#include <iostream>
#include <cmath>
using namespace std;

struct coords
{
	short x;
	short y;
};

struct parall
{
	coords a, b, c, d;
};

double get_len(coords a, coords b)
{
	return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}
int main() // говнокод пофиксить бы надо
{
	short count;
	parall* p;

	cin >> count;
	p = new parall[count];

	for (short i = 0; i < count; i++)
	{
		cin >> p[i].a.x >> p[i].a.y >> p[i].b.x >> p[i].b.y >> p[i].c.x >> p[i].c.y >> p[i].d.x >> p[i].d.y;
	}

	for (short i = 0; i < count; i++)
	{
		if (get_len(p[i].a, p[i].b) == get_len(p[i].c, p[i].d) && get_len(p[i].b, p[i].c) == get_len(p[i].a, p[i].d)
			&& (abs(p[i].a.x - p[i].b.x) == abs(p[i].c.x - p[i].d.x)) && (abs(p[i].a.x - p[i].d.x) == abs(p[i].c.x - p[i].b.x))
			&& (abs(p[i].a.y - p[i].b.y) == abs(p[i].c.y - p[i].d.y)) && (abs(p[i].a.y - p[i].d.y) == abs(p[i].c.y - p[i].b.y)))
		{
			cout << "YES" << endl;
		}
		else if (get_len(p[i].a, p[i].c) == get_len(p[i].b, p[i].d) && get_len(p[i].b, p[i].c) == get_len(p[i].a, p[i].d)
			&& (abs(p[i].a.x - p[i].c.x) == abs(p[i].b.x - p[i].d.x)) && (abs(p[i].a.x - p[i].d.x) == abs(p[i].c.x - p[i].b.x))
			&& (abs(p[i].a.y - p[i].c.y) == abs(p[i].b.y - p[i].d.y)) && (abs(p[i].a.y - p[i].d.y) == abs(p[i].c.y - p[i].b.y)))
		{
			cout << "YES" << endl;
		}
		else if (get_len(p[i].a, p[i].c) == get_len(p[i].b, p[i].d) && get_len(p[i].b, p[i].a) == get_len(p[i].c, p[i].d)
			&& (abs(p[i].a.x - p[i].c.x) == abs(p[i].b.x - p[i].d.x)) && (abs(p[i].a.x - p[i].b.x) == abs(p[i].c.x - p[i].d.x))
			&& (abs(p[i].a.y - p[i].c.y) == abs(p[i].b.y - p[i].d.y)) && (abs(p[i].a.y - p[i].b.y) == abs(p[i].c.y - p[i].d.y)))
		{
			cout << "YES" << endl;
		}
		else
			cout << "NO" << endl;
	}
}
