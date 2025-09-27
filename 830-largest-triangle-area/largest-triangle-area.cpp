class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n=points.size();
        double maxarea=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    double x1=points[i][0];
                    double y1=points[i][1];

                    double x2=points[j][0];
                    double y2=points[j][1];

                    double x3=points[k][0];
                    double y3=points[k][1];

                    double a=hypot(x2-x1,y2-y1);
                    double b=hypot(x3-x2,y3-y2);
                    double c=hypot(x3-x1,y3-y1);
                    double s=(a+b+c)*0.5;

                    double area = sqrt(s*(s-a)*(s-b)*(s-c));

                    maxarea=max(maxarea,area);

                }
            }
        }
        return maxarea;
    }
};