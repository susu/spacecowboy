#include <sc/phi/Accessory.hpp>

sc::phi::Accessory::Accessory()
  : evt::Handler()
  , m_physicalModel( nullptr )
  , m_owningObject( nullptr )
  , m_sector( nullptr )
{
}


void
sc::phi::Accessory::initialize( Object& owner, Model& physicalModel, Sector& sector )
{
  m_owningObject = &owner;
  m_physicalModel = &physicalModel;
  m_sector = &sector;
}


void
sc::phi::Accessory::subscribe( sc::evt::Registry& )
{
}


sc::phi::Accessory::~Accessory()
{
}

