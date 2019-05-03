#include <stdio.h>
#include <string.h>

// Does not give correct result for [(])
// The correct way is to use a stack.
// when seeing open brackets; push to stack
// when seeing close brackets, check stack not empty
// and that brackets are of same type.
// if stack is empty after processing string.. balanced
// else unbalanced.

char s[100000];

int checkBalanced(char s[], int i, int size, int nc, int ns, int np) {
    if (i == size) {
        if (nc==0 && ns==0 && np==0)
            return 1;
        else
            return 0;
    }
    
    if (s[i]=='(') np++;
    if (s[i]=='[') ns++;
    if (s[i]=='{') nc++;
    
    if (s[i]==')') np--;
    if (s[i]==']') ns--;
    if (s[i]=='}') nc--;
    
    
    if (np<0 || ns<0 || nc<0) {
        return 0;
    }
    return checkBalanced(s, i+1, size, nc, ns, np);
}

int main() {
    freopen("paranthesis_checker.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        int n = strlen(s);
        if (checkBalanced(s, 0, n, 0, 0, 0)) {
            printf("balanced\n");
        }
        else {
            printf("not balanced\n");
        }
    }
    
	//code
	
	return 0;
}
