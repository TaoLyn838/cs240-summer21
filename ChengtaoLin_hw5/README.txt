In this program, I do three helper methods for my four 
mian methods, and one extre struct type call PolarAngle.

For PolarAngle data type: it is like a table or array that hold all 
number of angles after I calculated the angle between two points.
It has two variable: 1.i as index; 2.angle is the angle of points.

For main methods:
1. Point *createData(int seed, int n); I create a csv file call points.csv,
and use random methods to set up the pointers from driver.c file.

2. void LargestY(Point *p, int n); I use comparator 
cmpLargestY(Point *p, int size) to get largest Y index from data Points
 and return a point that hold largest Y-coordinate. 

3. int *sortAngle(Point *p, int n); I reate a sortedPoints.csv file. 
After I calulate all angles from points, I use quick sort to sort all 
angle of points. Then, make a integer pointer array to hold all 
values from sort angles.

4. void convexHull(Point* p,int *indexes,int n); Because I already sort
all angles, so I use mempy to copy all angles into an integer stuck
array. Let initialize a integer variable called top, that equals 2 because
it start with point a and b.Then, let the three points be prev, curr 
and next. Final, createa comparator if orientation of these points 
(considering them is greater zeroor not) is not counterclockwise, 
we discard c, otherwise we keep it.

For helper methods:
1.int cmpLargestY(Point *p, int size); find the largetest Y value from
each Points. Then, return the index of largestest Y.

2. int cmpQuickS_Angle(const void *p, const void *q); The comparator for 
the qsort method, that return 1, -1, and 0 which two angles are greater,
less, and equal to each other.

3.PolarAngle *sortAngleHelper(Point *p, size_t n, int size, int largest);
Using cosine to solve two points for get their polar angle.

Something else: Honestly, I search a lot of resource from Google for
understand the meaning of this program. Moreover, after I finish this
program, my values alaways unequal to the sample result. Then, I see
that I need to use srand48() and drand48() for this program. Instead 
to use srand() and (rand / RAND_MAX)

