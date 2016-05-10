#ifndef MAP_H
#define MAP_H
#include <vector>
#include <string>

class Map
{
    public:
        Map(int height, int width);
        Map(std::string path_to_file);
        //~Map();

        unsigned int Get_height() { return m_height; }
        //void Set_height(unsigned int val) { m_height = val; }
        unsigned int Get_width() { return m_width; }
        //void Set_width(unsigned int val) { m_width = val; }

        unsigned int m_height;
        unsigned int m_width;
        std::vector<std::vector<int>> m_layout;
    protected:

    private:
        std::string path_to_file;
};

#endif // MAP_H
