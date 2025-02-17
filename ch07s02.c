#include <stdio.h>
#include <math.h>

struct complex_struct {
	double x, y;
};

struct complex_struct make_from_real_img(double x, double y)
{
	struct complex_struct z;
	z.x = x;
	z.y = y;
	return z;
}

struct complex_struct make_from_mag_ang(double r, double A)
{
	struct complex_struct z;
	z.x = r * cos(A);
	z.y = r * sin(A);
	return z;
}

double real_part(struct complex_struct z)
{
	return z.x;
}

double img_part(struct complex_struct z)
{
	return z.y;
}

double magnitude(struct complex_struct z)
{
	return sqrt(z.x * z.x + z.y * z.y);
}

double angle(struct complex_struct z)
{
	return atan2(z.y, z.x);
}

struct complex_struct add_complex(struct complex_struct z1, struct complex_struct z2)
{
	return make_from_real_img(real_part(z1) + real_part(z2),
				  img_part(z1) + img_part(z2));
}

struct complex_struct sub_complex(struct complex_struct z1, struct complex_struct z2)
{
	return make_from_real_img(real_part(z1) - real_part(z2),
				  img_part(z1) - img_part(z2));
}

struct complex_struct mul_complex(struct complex_struct z1, struct complex_struct z2)
{
	return make_from_mag_ang(magnitude(z1) * magnitude(z2),
				 angle(z1) + angle(z2));
}

struct complex_struct div_complex(struct complex_struct z1, struct complex_struct z2)
{
	return make_from_mag_ang(magnitude(z1) / magnitude(z2),
				 angle(z1) - angle(z2));
}

void print_complex(struct complex_struct z)
{
    if (z.x == 0 && z.y == 0) {
        printf("0\n");
    } else if (z.x == 0) {
        printf("%lfi\n", z.y);
    } else if (z.y == 0) {
        printf("%lf\n", z.x);
    } else if (z.y > 0) {
        printf("%lf+%lfi\n", z.x, z.y);
    } else {
        printf("%lf%lfi\n", z.x, z.y);
	}
}

int GCD(int a, int b)
{
	if (a % b == 0) {
		return b;
	} else {
		GCD(b, a % b);
	}
}

struct rational
{
	int numerator, denominator;
};

struct rational simplify(struct rational num)
{
	struct rational result;
	result.numerator = num.numerator / GCD(num.numerator, num.denominator);
	result.denominator = num.denominator / GCD(num.numerator, num.denominator);
	return result;
}

struct rational make_rational(int numerator, int denominator)
{
	struct rational a;
	a.numerator = numerator;
	a.denominator = denominator;
	simplify(a);
	return a;
}

struct rational add_rational(struct rational a, struct rational b)
{
	struct rational result;
	if (a.denominator == b.denominator) {
		result.numerator = (a.numerator + b.numerator);
		result.denominator = a.denominator;
	} else {
		result.denominator = a.denominator * b.denominator;
		result.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
	}
	return simplify(result);
}

struct rational sub_rational(struct rational a, struct rational b)
{
	struct rational result;
	if (a.denominator == b.denominator) {
		result.numerator = (a.numerator - b.numerator);
		result.denominator = a.denominator;
	} else {
		result.denominator = a.denominator * b.denominator;
		result.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
	}
	return simplify(result);
}

struct rational mul_rational(struct rational a, struct rational b)
{
	struct rational result;
	result.numerator = a.numerator * b.numerator;
	result.denominator = a.denominator * b.denominator;
	return simplify(result);
}

struct rational div_rational(struct rational a, struct rational b)
{
	struct rational result;
	result.numerator = a.numerator * b.denominator;
	result.denominator = a.denominator * b.numerator;
	return simplify(result);
}

void print_rational(struct rational num)
{
	if (num.numerator == 0) {
		printf("0\n");
	} else {
		printf("%d/%d\n", num.numerator, num.denominator);
	}
}

int main()
{
    double x, y;
    printf("Input real part: ");
    scanf("%lf", &x);
    printf("Input img part: ");
    scanf("%lf", &y);
    // struct complex_struct z1 = make_from_real_img(x, y);
    struct complex_struct z1 = {x, y};
	struct complex_struct z2 = add_complex(z1, z1);
	struct complex_struct z3 = sub_complex(z2, z1);

    print_complex(z1);
	printf("\n");
    print_complex(z2);
	printf("\n");
    print_complex(sub_complex(z2, z1));
	printf("\n");
    print_complex(mul_complex(z2, z1));
	printf("\n");
    print_complex(div_complex(z2, z1));
	printf("\n");
	// struct rational a = make_rational(1, 8); /* a=1/8 */
	// struct rational b = make_rational(-1, 8); /* b=-1/8 */
	// print_rational(add_rational(a, b));
	// print_rational(sub_rational(a, b));
	// print_rational(mul_rational(a, b));
	// print_rational(div_rational(a, b));

    return 0;
}
