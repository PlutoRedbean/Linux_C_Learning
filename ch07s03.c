#include <stdio.h>
#include <math.h>

enum coordinate_type { RECTANGULAR = 1, POLAR };

struct complex_struct {
    enum coordinate_type t;
	double x, y;
};

struct complex_struct make_from_real_img(double x, double y)
{
	struct complex_struct z;
    z.t = RECTANGULAR;
	z.x = x;
	z.y = y;
	return z;
}

struct complex_struct make_from_mag_ang(double r, double A)
{
	struct complex_struct z;
    z.t = POLAR;
	z.x = r;    //模长
	z.y = A;    //角度
	return z;
}

double real_part(struct complex_struct z)
{
    switch (z.t) {
    case RECTANGULAR :
        return z.x;
        break;
    case POLAR :
        return z.x * cos(z.y);
        break;
    }
}

double img_part(struct complex_struct z)
{
	switch (z.t) {
    case RECTANGULAR :
        return z.y;
        break;
    case POLAR :
        return z.x * sin(z.y);
        break;
    }
}

double magnitude(struct complex_struct z)
{
    switch (z.t) {
    case RECTANGULAR :
        return sqrt(z.x * z.x + z.y * z.y);
        break;
    case POLAR :
        return z.x;
        break;
    }
}

double angle(struct complex_struct z)
{
    switch (z.t) {
    case RECTANGULAR :
        return atan2(z.y, z.x);
        break;
    case POLAR :
        return z.y;
        break;
    }
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
    if (real_part(z) == 0 && img_part(z) == 0) {
        printf("0\n");
    } else if (real_part(z) == 0) {
        printf("%lfi\n", img_part(z));
    } else if (img_part(z) == 0) {
        printf("%lf\n", real_part(z));
    } else if (img_part(z) > 0) {
        printf("%lf+%lfi\n", real_part(z), img_part(z));
    } else {
        printf("%lf%lfi\n", real_part(z), img_part(z));
	}
}

int main()
{
    double x, y;
    printf("Input real part: ");
    scanf("%lf", &x);
    printf("Input img part: ");
    scanf("%lf", &y);
    struct complex_struct z1 = make_from_real_img(x, y);
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

    return 0;
}
