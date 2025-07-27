/*
Suppose you are at a party with n people labeled from 0 to n - 1 and among them, there may exist one celebrity. The definition of a celebrity is that all the other n - 1 people know the celebrity, but the celebrity does not know any of them.

Now you want to find out who the celebrity is or verify that there is not one. You are only allowed to ask questions like: "Hi, A. Do you know B?" to get information about whether A knows B. You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).

You are given an integer n and a helper function bool knows(a, b) that tells you whether a knows b. Implement a function int findCelebrity(n). There will be exactly one celebrity if they are at the party.

Return the celebrity's label if there is a celebrity at the party. If there is no celebrity, return -1.

Note that the n x n 2D array graph given as input is not directly available to you, and instead only accessible through the helper function knows. graph[i][j] == 1 represents person i knows person j, wherease graph[i][j] == 0 represents person j does not know person i.
*/
/* The knows API is defined for you.
      bool knows(int a, int b); */
/*
Time Complexity : O(n).

Our code is split into 2 parts.

The first part finds a celebrity candidate. This requires doing n−1 calls to knows(...) API, and so is O(n).

The second part is the same as before—checking whether or not a given person is a celebrity. We determined that this is O(n).

Therefore, we have a total time complexity of O(n+n)=O(n).
*/
class Solution {
    int n;
    bool is_celeb(int c){
        for(int j=0;j<n;j++){
            if(j==c){
                continue;
            }
            if(knows(c,j) || !knows(j,c)){
                return false;
            }
        }
        return true;
    }
public:
    int findCelebrity(int n) {
        this->n=n;
        int cand=0;
        for(int i=0;i<n;i++){
            if(knows(cand,i)){
                cand=i;
            }
        }
        if(is_celeb(cand)){
            return cand;
        }
        return -1;
    }
};
