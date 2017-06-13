#include <OgreSceneNode.h>
#include "EntityFactory.hpp"
#include "Entity.hpp"
#include "AnimatedEntity.hpp"

Entity EntityFactory::spawnOgreHead()
{
  Entity ogre(renderer, "ogrehead.mesh");

  ogre.getOgre()->setCastShadows(false);
  ogre.getNode()->setScale(1.0f / 150.0f, 1.0f / 150.0f, 1.0f / 150.0f);
  return ogre;
}

AnimatedEntity EntityFactory::spawnArcher(Skins::Skin skin)
{
  AnimatedEntity archer(renderer, skin);

  // TODO : Put the rotation here
  archer.getEntity().getOgre()->setCastShadows(false);
  archer.getEntity().getNode()->setScale(1.0f / 150.0f, 1.0f / 150.0f, 1.0f / 150.0f);
  return archer;
}

Ogre::Light *EntityFactory::createLight(Entity &target)
{
  auto light(renderer.getSceneManager().createLight());
  light->setType(Ogre::Light::LT_POINT);

  light->setDiffuseColour(1.0f, 0.7f, 0.4f);
  light->setSpecularColour(1.0f, 1.0f, 1.0f);
  light->setDirection(0.f, -0.1f, 1.f);
  light->setPosition(0, 120, 0);
  //light->setSpotlightOuterAngle(Ogre::Degree(360));
  //light->setSpotlightInnerAngle(Ogre::Degree(90));
  light->setAttenuation(500, 1.0f, 0.007f, 0.0f);
  target.getNode()->attachObject(light);
  return light;
}
