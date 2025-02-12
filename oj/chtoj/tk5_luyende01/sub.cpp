#include< b i t s / s tdc ++.h>
using namespace std ;
const int _ s i z e = 1e6 + 5;
int n , a [ _ s i z e ] , p [ _ s i z e ] , i , j , q ,ma=0 ,mi=1e18 ;
int bns ( int x ) {
int ans = n + 1;
int l =1;
int r=n ;
while ( l <=r ) {
int mid = ( l +r ) / 2 ;
i f ( p [mid ] <= x ) {
ans=mid ;
r=mid
−1;

}
else l =mid+1;
}
return ans ;
}
int main ( ) {
i o s : : sync _w i th _s td i o ( 0 ) ; c in . t i e ( ) ;
c in >> n >> q ;
for ( i = 1 ; i <= n ; i ++) c in >> a [ i ] ;
p [ 1 ] = a [ 1 ] ;
for ( i = 2 ; i <= n ; i ++)
p [ i ] = min ( p [ i

−1] , a [ i ] ) ;
for ( i = 1 ; i <= n ; i ++)
ma=max (ma , i

− bns ( a [ i ]
−q ) ) ;
for ( i = 1 ; i <= n ; i ++ ) {
int t = bns ( a [ i ]
−q ) ;
i f ( i
−t == ma ) {
cout << t << " " << i ;
return 0;
}
}
cout << 0;
return 0;
