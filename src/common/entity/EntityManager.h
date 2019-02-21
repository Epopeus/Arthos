#pragma once


#include <common/type/OptionalRef.h>
#include "Entity.h"
#include "Name.h"

class EntityManager {
public:
    EntityManager();

    Entity& create() {

    }

    template<typename C>
    C& getComponent(Guid& entityId) {

    }

    OptionalRef<Guid> findEntityId(Name& entityName);

    template <typename C, typename ... Args>
    C assign(Guid& entityId, Args && ... args) {
    }
};

