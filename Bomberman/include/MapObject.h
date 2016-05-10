#ifndef MAPOBJECT_H
#define MAPOBJECT_H


class MapObject
{
    public:
        MapObject();
        virtual ~MapObject();

        void Draw();
        return Get_id() { return m_id; }

    protected:

    private:
        unsigned int m_id;
        SDL_Texture *m_tex;
};

#endif // MAPOBJECT_H
