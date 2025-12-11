#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int m = 1750;
int n;

int main() {
    n = m + (m - 1);


    freopen("circuit.qasm", "w", stdout);

    printf("OPENQASM 2.0; \ninclude \"qelib1.inc\"; \nqreg q[%d];\n\n", n + 2);

    /*
        anc = q[0];
        q[n] = q[1..n];
        t = q[n + 1];
    */


    // first part
    printf("ccx q[%d], q[%d], q[%d];\n", n - 1, n, 0);

    for (int i = m - 2; i >= 2;i--) {
        printf("ccx q[%d], q[%d], q[%d];\n", 2 * i - 1, 2 * i + 1, 2 * i + 2);
    }

    printf("ccx q[%d], q[%d], q[%d];\n", 1, 3, 4);
    
    for (int i = 2; i <= m - 2;i++) {
        printf("ccx q[%d], q[%d], q[%d];\n", 2 * i - 1, 2 * i + 1, 2 * i + 2);
    }

    printf("ccx q[%d], q[%d], q[%d];\n", n - 1, n, 0);

    for (int i = m - 2; i >= 2;i--) {
        printf("ccx q[%d], q[%d], q[%d];\n", 2 * i - 1, 2 * i + 1, 2 * i + 2);
    }

    printf("ccx q[%d], q[%d], q[%d];\n", 1, 3, 4);

    for (int i = 2; i <= m - 2;i++) {
        printf("ccx q[%d], q[%d], q[%d];\n", 2 * i - 1, 2 * i + 1, 2 * i + 2);
    }


    // second part
    printf("ccx q[%d], q[%d], q[%d];\n", n, 0, n + 1);

    for (int i = m - 1;i >= 3;i--) {
        printf("ccx q[%d], q[%d], q[%d];\n", 2 * i - 1, 2 * i, 2 * i + 1);
    }

    printf("ccx q[%d], q[%d], q[%d];\n", 2, 4, 5);

    for (int i = 3;i <= m - 1;i++) {
        printf("ccx q[%d], q[%d], q[%d];\n", 2 * i - 1, 2 * i, 2 * i + 1);
    }

    printf("ccx q[%d], q[%d], q[%d];\n", n, 0, n + 1);

    for (int i = m - 1;i >= 3;i--) {
        printf("ccx q[%d], q[%d], q[%d];\n", 2 * i - 1, 2 * i, 2 * i + 1);
    }

    printf("ccx q[%d], q[%d], q[%d];\n", 2, 4, 5);

    for (int i = 3;i <= m - 1;i++) {
        printf("ccx q[%d], q[%d], q[%d];\n", 2 * i - 1, 2 * i, 2 * i + 1);
    }

    // third part
    printf("ccx q[%d], q[%d], q[%d];\n", n - 1, n, 0);

    for (int i = m - 2; i >= 2;i--) {
        printf("ccx q[%d], q[%d], q[%d];\n", 2 * i - 1, 2 * i + 1, 2 * i + 2);
    }

    printf("ccx q[%d], q[%d], q[%d];\n", 1, 3, 4);
    
    for (int i = 2; i <= m - 2;i++) {
        printf("ccx q[%d], q[%d], q[%d];\n", 2 * i - 1, 2 * i + 1, 2 * i + 2);
    }

    printf("ccx q[%d], q[%d], q[%d];\n", n - 1, n, 0);

    for (int i = m - 2; i >= 2;i--) {
        printf("ccx q[%d], q[%d], q[%d];\n", 2 * i - 1, 2 * i + 1, 2 * i + 2);
    }

    printf("ccx q[%d], q[%d], q[%d];\n", 1, 3, 4);

    for (int i = 2; i <= m - 2;i++) {
        printf("ccx q[%d], q[%d], q[%d];\n", 2 * i - 1, 2 * i + 1, 2 * i + 2);
    }

    // fourth part
    printf("ccx q[%d], q[%d], q[%d];\n", n, 0, n + 1);

    for (int i = m - 1;i >= 3;i--) {
        printf("ccx q[%d], q[%d], q[%d];\n", 2 * i - 1, 2 * i, 2 * i + 1);
    }

    printf("ccx q[%d], q[%d], q[%d];\n", 2, 4, 5);

    for (int i = 3;i <= m - 1;i++) {
        printf("ccx q[%d], q[%d], q[%d];\n", 2 * i - 1, 2 * i, 2 * i + 1);
    }

    printf("ccx q[%d], q[%d], q[%d];\n", n, 0, n + 1);

    for (int i = m - 1;i >= 3;i--) {
        printf("ccx q[%d], q[%d], q[%d];\n", 2 * i - 1, 2 * i, 2 * i + 1);
    }

    printf("ccx q[%d], q[%d], q[%d];\n", 2, 4, 5);

    for (int i = 3;i <= m - 1;i++) {
        printf("ccx q[%d], q[%d], q[%d];\n", 2 * i - 1, 2 * i, 2 * i + 1);
    }




    freopen("pre.hsl", "w", stdout);
    printf("Constants\nc1 := 1 / sqrt2\nc2 := 1 / sqrt2\nExtended Dirac\n{ c1 |0i> + c2 |1i> : |i|=%d}\n", n + 1);

    freopen("post.hsl", "w", stdout);
    printf("Constants\nc1 := 1 / sqrt2\nc2 := 1 / sqrt2\nExtended Dirac\n{ c1 |0i> + c2 |1i> : |i|=%d}\n", n + 1);


}