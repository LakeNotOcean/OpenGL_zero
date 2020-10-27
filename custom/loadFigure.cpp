#include "loadFigure.h"


using namespace std;

slash_is_space::slash_is_space():
    std::ctype<char>(get_table()) {}

std::ctype_base::mask const* slash_is_space::get_table()
{
    static mask rc[table_size];
    rc['/'] = std::ctype_base::space;
    rc['\n'] = std::ctype_base::space;
    rc[' '] = std::ctype_base::space;
    return &rc[0];
}

void loadInput(string fileName, vector<Vector3f>& vecv, vector<Vector3f>& vecn, vector<face>& vecf)
{
    ifstream ifs(fileName);
    if (!ifs.is_open())
        return;
    stringstream ss;
    string s;
    Vector3f v;
    int faceInput[Indexes::maxFaceIndex] = { 0,0,0,0,0,0,0,0,0 };
    ss << ifs.rdbuf();
    ss.imbue(locale(ss.getloc(), new slash_is_space));
    while (!ss.eof())
    {
        ss >> s;
        if (s == "v")
        {
            ss >> v[0] >> v[1] >> v[2];
            vecv.push_back(v);
        }
        else if (s == "vn")
        {
            ss >> v[0] >> v[1] >> v[2];
            vecn.push_back(v);
        }
        else if (s == "f")
        {
            for (int i = 0; i < Indexes::maxFaceIndex; ++i)
            {
                ss >> faceInput[i];
            }
            vecf.push_back(face(faceInput));
        }
    }
    cout << "Figure is loaded" << endl;
    // load the OBJ file here


}