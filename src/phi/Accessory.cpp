#include <sc/phi/Accessory.hpp>

sc::phi::Accessory::Accessory()
  : evt::Handler()
  , m_physicalModel( nullptr )
{
}


void
sc::phi::Accessory::initialize( Model& physicalModel )
{
  m_physicalModel = &physicalModel;
}


sc::phi::Accessory::~Accessory()
{
}

