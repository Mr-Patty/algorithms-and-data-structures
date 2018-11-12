#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

typedef unsigned long long int data_t;

inline char simb( data_t val ) {
    return val < 10 ? '0' + val : 'A' + val - 10;
}

int main( ) {
    
    data_t ch, zn;
    cin >> ch;
    cin >> zn;
    string sval( "0." );
    data_t ost = ch % zn;
    vector<int> list(zn, -1);
    for( int i = 0; ; i++ ) {
        data_t ch = ost * 10;
        ost = ch % zn;
        sval.push_back( simb( ch / zn ) );
        if( 0 == ost ) break;
        if( list[ ost ] < 0 )
            list[ ost ] = i;
        else {
            ost = i - list[ ost ];
            break;
        }
    };
    if( ost != 0 ) {
        string::iterator is = sval.end() - ost;
        sval.insert( is, '(' );
        sval += ")";
    }
    cout << sval << endl;
    return 0;
}