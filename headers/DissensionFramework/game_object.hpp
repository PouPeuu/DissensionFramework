#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

namespace DissensionFramework {
    class GameObject
    {
    private:
        
    public:
        GameObject();

        virtual void update();
        virtual void draw() const;
    };
}

#endif