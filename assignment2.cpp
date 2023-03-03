/*
Youssef Aglan 900222720
Assignment # 2
*/

#include <iostream>

#include <ctime>

#include <cmath>

using namespace std;

// Class of member objects of points with x & y coordinates
class Points
{
private:
    float x;
    float y;

public:
    Points()
    {
        x = 0;
        y = 0;
    }

    Points(float floatx, float floaty)
    {
        x = floatx;
        y = floaty;
    }

    void setx(float floatx)
    {
        x = floatx;
    }

    float getx()
    {
        return x;
    }

    void sety(float floaty)
    {
        y = floaty;
    }

    float gety()
    {
        return y;
    }

    void displayPoint()
    {
        cout << "(" << x << "," << y << ")";
    }

    float getdistance(Points p)
    {
        return (sqrt(pow(x - p.x, 2) + pow(y - p.y, 2)));
    }
};
// Determines the center of a cluster of points
Points center(Points * a, int n)
{
    // Counts sum and divides by size of array
    float sum1 = 0, average1 = 0;;
    float sum2 = 0, average2 = 0;;
    for (int i = 0; i < n; i++)
    {
        sum1 = sum1 + a[i].getx();
        sum2 = sum2 + a[i].gety();
    }
    average1 = sum1 / n;
    average2 = sum2 / n;
    // Creates a point to return the center coordinates
    Points c(average1, average2);

    return c;
}
// Determines which cluster a point is closest to
void cluster(Points* clusterA, Points* clusterB, Points p, int n)
{
    Points center1, center2;
    float distance1, distance2;
    // calls upon function center to determine that of the clusters
    center1 = center(clusterA, n);
    center2 = center(clusterB, n);
    // Uses the elucidean formula to get distance from center to point p
    distance1 = p.getdistance(center1);
    distance2 = p.getdistance(center2);

// the smallest distance from point p is the cluster the point p belongs to
    if (distance1 < distance2)
    {
        cout << "point belongs to cluster A" << endl;
    }
    else
    {
        cout << "point belongs to cluster B" << endl;
    }

}

int main()
{
    srand(time(NULL));
    int size;
    cout << "Number of points in cluster A & B: \n";
    cin >> size;
    // two dynamic arrays for clusters A & B
    Points * centerA = new Points[size];
    Points * centerB  = new Points[size];
    // 1d array of twenty points
    Points P[20];
    // outputs points of cluster A
    cout << "cluster A: \n";
    for (int x = 0; x < size; x++)
    {
        centerA[x].setx((rand()%19)+ 71);
        centerA[x].sety((rand()%19)+ 71);
        centerA[x].displayPoint();
        cout << endl;
    }
    // outputs points of cluster B
    cout << "cluster B: \n";
    for (int x = 0; x < size; x++)
    {
        centerB[x].setx((rand()%19)+ 21);
        centerB[x].sety((rand()%19)+ 21);
        centerB[x].displayPoint();
        cout << endl;
    }
    // calls the cluster function for each point in array of points
    for (int x = 0; x < 20; x++)
    {
        P[x].setx((rand()%94)+ 6);
        P[x].sety((rand()%94)+ 6);
        cluster(centerA, centerB, P[x], size);
    }


}
