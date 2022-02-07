#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

bool WriteRandomBinToFile( string file_name, size_t len );

int main()
{
    const string file_name = "../bitsream.bin";
    const size_t len = 1024;

    if ( WriteRandomBinToFile( file_name, len ) )
    {
        cout << len << " word is written successfully to " << file_name << endl;
    } 
    else
    {
        cout << "Failed to write " << endl;
    }
    return 0;
}

bool WriteRandomBinToFile( string file_name, size_t word_count )
{
    ofstream tgt_file( file_name, ios::out | ios::binary | ios::trunc );
    if ( tgt_file.is_open() )
    {
        srand( time( nullptr ) );
        while ( word_count-- > 0 )
        {
            uint32_t val = rand() % UINT32_MAX;
            tgt_file.write( reinterpret_cast<const char*> (&val), sizeof(val) );
        }
        tgt_file.close();
        return true;
    }
    return false;
}
