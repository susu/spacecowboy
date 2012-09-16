#include <sc/phi/Accessory.hpp>

void
sc::phi::Accessory::initialize( Model& physicalModel )
{
  m_physicalModel = &physicalModel;
}


sc::phi::Accessory::~Accessory()
{
}

