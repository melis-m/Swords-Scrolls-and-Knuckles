#ifndef UIOVERLAY_HPP
# define UIOVERLAY_HPP

# include <Overlay/OgreOverlayManager.h>
# include <Overlay/OgreOverlay.h>
# include "Game.hpp"

class UIOverlay {

	public:
		UIOverlay() = default;
		UIOverlay(UIOverlay const &) = delete;
		UIOverlay(UIOverlay &&) = delete;
		UIOverlay &operator=(UIOverlay const &) = delete;
		UIOverlay &operator=(UIOverlay &&) = delete;
		virtual ~UIOverlay(void) = default;
		
		static Ogre::Vector2 pixelsToRelative(Ogre::Vector2);
		static Ogre::Vector2 relativeToPixels(Ogre::Vector2);
		
		void setOverlay(Ogre::Overlay *);
		virtual void init(Ogre::OverlayManager *) = 0;

	private:
	protected:
		Ogre::Overlay *overlay;
};

#endif // !UIOVERLAY_HPP
