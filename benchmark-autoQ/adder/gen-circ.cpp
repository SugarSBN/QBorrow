#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int n = 200;

#define a(i) (i - 1)
#define q(i) (i + n - 2)

int main() {


    freopen("circuit.qasm", "w", stdout);

    printf("OPENQASM 2.0; \ninclude \"qelib1.inc\"; \nqreg q[%d];\n\n", n - 1 + n);

    printf("cx q[%d], q[%d];\n", a(n - 1), q(n));

    for (int i = n - 1;i >= 2;i--) {
        printf("cx q[%d], q[%d];\n", q(i), a(i));
        printf("x q[%d];\n", q(i));
        printf("ccx q[%d], q[%d], q[%d];\n", a(i - 1), q(i), a(i));
    }

    printf("cx q[%d], q[%d];\n", q(1), a(1));

    for (int i = 2;i <= n - 1;i++) {
        printf("ccx q[%d], q[%d], q[%d];\n", a(i - 1), q(i), a(i));
    }

    printf("cx q[%d], q[%d];\n", a(n - 1), q(n));

    printf("x q[%d];\n", q(n));

    for (int i = (n - 1);i >= 2;i--) {
        printf("ccx q[%d], q[%d], q[%d];\n", a(i - 1), q(i), a(i));
    }

    printf("cx q[%d], q[%d];\n", q(1), a(1));

    for (int i = 2;i <= n - 1;i++) {
        printf("ccx q[%d], q[%d], q[%d];\n", a(i - 1), q(i), a(i));
        printf("x q[%d];\n", q(i));
        printf("cx q[%d], q[%d];\n", q(i), a(i));
    }



    freopen("pre.hsl", "w", stdout);
    printf("Constants\nc1 := 1 / sqrt2\nc2 := 1 / sqrt2\nExtended Dirac\n{ c1 |0i> + c2 |1i> : |i|=%d}\n", n + n - 2);

    freopen("post.hsl", "w", stdout);
    printf("Constants\nc1 := 1 / sqrt2\nc2 := 1 / sqrt2\nExtended Dirac\n{ c1 |0i> + c2 |1i> : |i|=%d}\n", n + n - 2);


}