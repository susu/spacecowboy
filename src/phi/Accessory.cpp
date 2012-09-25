#include <sc/phi/Accessory.hpp>

sc::phi::Accessory::Accessory()
  : evt::Handler()
  , m_physicalModel( nullptr )
  , m_owningObject( nullptr )
{
}


void
sc::phi::Accessory::initialize( Object& owner, Model& physicalModel )
{
  m_owningObject = &owner;
  m_physicalModel = &physicalModel;
}


sc::phi::Accessory::~Accessory()
{
}

