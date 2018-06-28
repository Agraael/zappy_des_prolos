//
// Created by Ludovica Pagliarani on 07/05/2018.
//

#include "IrrlichtLib.hpp"

graphic::IrrlichtLib::IrrlichtLib()
{
	_screenSize = {2080, 1720};
	_device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(_screenSize.x, _screenSize.y), 16, false, false, false, 0);
	if (!_device)
		std::cout << "error device" << std::endl;
	_device->setWindowCaption(L"INDIE DES BESTOS");
	_driver = _device->getVideoDriver();
	_sceneManager = _device->getSceneManager();
	_guiEnv = _device->getGUIEnvironment();
	_eventManager = std::make_shared<graphic::LibEventManager>(t_contextRecEvnt{_device, 0, nullptr});
	_device->setEventReceiver(_eventManager.get());
	_light = 255;
}

graphic::IrrlichtLib::~IrrlichtLib()
{
	_device->drop();
}

void	graphic::IrrlichtLib::displayAll()
{
	_driver->beginScene(true, true, irr::video::SColor(50,164,224,229));
	_sceneManager->drawAll();
	_guiEnv->drawAll();
	_driver->endScene();
}

irr::video::ITexture	*graphic::IrrlichtLib::findTextureOrCreate(const std::string &path)
{
	auto it = _mapTexture.find(path);
	if (it == _mapTexture.end()) {
		auto texture = _driver->getTexture(path.c_str());
		_mapTexture[path] = texture;
		return texture;
	}
	return it->second;

}

irr::gui::IGUIImage	*graphic::IrrlichtLib::drawImage(const infos_t &infos)
{
	auto texture = findTextureOrCreate(infos._path);
	_driver->enableMaterial2D();
	irr::gui::IGUIImage *img = _guiEnv->addImage(texture, irr::core::position2d<int>(infos._x, infos._y));
	img->setScaleImage(true);
	img->setMinSize(irr::core::dimension2du(infos._w, infos._h));
	img->setMaxSize(irr::core::dimension2du(infos._maxW, infos._maxH));
	return (img);
}

irr::gui::IGUIButton	*graphic::IrrlichtLib::printButton(const infos_t &infos)
{
	std::wstring wideStr = std::wstring(infos._name.begin(), infos._name.end());
	const wchar_t *nameToPrint = wideStr.c_str();
	std::wstring wideStrDesc = std::wstring(infos._desc.begin(), infos._desc.end());
	const wchar_t *descriptionToPrint = wideStrDesc.c_str();
	irr::gui::IGUIButton *butCustom = _guiEnv->addButton(irr::core::rect<irr::s32>(infos._x, infos._y, infos._w, infos._h), 0, infos._type, nameToPrint, descriptionToPrint);
	butCustom->setDrawBorder(0);
	butCustom->setImage(_driver->getTexture(infos._path.c_str()));
	butCustom->setScaleImage(true);
	butCustom->setUseAlphaChannel(true);
	return (butCustom);

}

irr::gui::IGUIButton	*graphic::IrrlichtLib::printButton(const infos_t &infos, irr::gui::IGUIEnvironment *env)
{
	std::wstring wideStr = std::wstring(infos._name.begin(), infos._name.end());
	const wchar_t *nameToPrint = wideStr.c_str();
	std::wstring wideStrDesc = std::wstring(infos._desc.begin(), infos._desc.end());
	const wchar_t *descriptionToPrint = wideStrDesc.c_str();
	irr::gui::IGUIButton *butCustom = env->addButton(irr::core::rect<irr::s32>(infos._x, infos._y, infos._w, infos._h), 0, infos._type, nameToPrint, descriptionToPrint);
	butCustom->setDrawBorder(0);
	butCustom->setImage(_driver->getTexture(infos._path.c_str()));
	butCustom->setScaleImage(true);
	butCustom->setUseAlphaChannel(true);
	return (butCustom);

}

void	graphic::IrrlichtLib::setCamera(irr::scene::ISceneNode * child, vec3df pos)
{
	irr::scene::ICameraSceneNode *cam= _sceneManager->addCameraSceneNode();
	cam->bindTargetAndRotation(true);
	cam->setPosition(irr::core::vector3df(pos.x, pos.y, pos.z));
	cam->setParent(child);
	cam->setID(1);
}

void	graphic::IrrlichtLib::setCamera(const vec3df &pos, const vec3df &target)
{
	irr::scene::ICameraSceneNode *cam = _sceneManager->addCameraSceneNode();
	cam->setPosition(irr::core::vector3df(pos.x, pos.y, pos.z));
	cam->setTarget(irr::core::vector3df(target.x, target.y, target.z));
	cam->setID(1);
}

irr::scene::ISceneNode	*graphic::IrrlichtLib::createCube(const vec3df &pos, const std::string &path, irr::s32 id)
{
	irr::scene::ISceneNode *n = _sceneManager->addCubeSceneNode(1);

	if (n) {
		n->setPosition(irr::core::vector3df(pos.x, pos.y, pos.z));
		n->setMaterialTexture(0, _driver->getTexture(path.c_str()));
		n->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		n->setID(id);
	}
	return (n);
}

irr::scene::ISceneNode  *graphic::IrrlichtLib::createPlayer(const vec3df &pos, const std::string &path, irr::s32 id)
{
    irr::scene::IAnimatedMesh* mesh = _sceneManager->getMesh("../Assets/stay.b3d");
    irr::scene::ISceneNode *node = _sceneManager->addAnimatedMeshSceneNode(mesh);
	if (node) {
        node->setScale(irr::core::vector3df(1.8f, 1.8f, 1.8f));
        node->setPosition(irr::core::vector3df(pos.x ,pos.y, pos.z));
        node->setRotation(irr::core::vector3df(60.f, 0.f, 0.f));
        node->setMaterialTexture(0, _driver->getTexture(path.c_str()));
        node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        node->setID(id);
    }
    return (node);

}

irr::scene::ISceneNode	*graphic::IrrlichtLib::createSphere(const vec3df &pos, const std::string &path, irr::s32 id, const sphere_t &sph)
{
	irr::scene::ISceneNode *node = _sceneManager->addSphereSceneNode(sph.diameter);

	if (node) {
		node->setPosition(irr::core::vector3df(pos.x,pos.y, pos.z));
		node->setMaterialTexture(0, _driver->getTexture(path.c_str()));
		node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		node->setID(id);
		if (sph.rotate != true)
			node->setRotation(irr::core::vector3df(0.5, 0, 0));
	}
	return (node);
}

void	graphic::IrrlichtLib::drawText(size_t x, size_t y, size_t fontSize, const std::string &text)
{
	std::wstring wideStr = std::wstring(text.begin(), text.end());
	const wchar_t *wideCStr = wideStr.c_str();
	_guiEnv->addStaticText(wideCStr, irr::core::rect<irr::s32>(x, y, x + 100, y + 100), true);
	(void)(fontSize);
}

void graphic::IrrlichtLib::setSkinTransparency(irr::s32 alpha, irr::gui::IGUISkin *skin)
{
    for (irr::s32 i=0; i < irr::gui::EGDC_COUNT ; ++i)
    {
        irr::video::SColor col = skin->getColor((irr::gui::EGUI_DEFAULT_COLOR)i);
        col.setAlpha(alpha);
        std::cout << "print Alpha " << alpha << std::endl;
        skin->setColor((irr::gui::EGUI_DEFAULT_COLOR)i, col);
    }
}

void    graphic::IrrlichtLib::modifyLight(int nbr)
{
    if ((nbr == -10 && _light >= 10) || (nbr == 10 && _light <= 245)) {
        _light = _light + nbr;
        setSkinTransparency(_light, _guiEnv->getSkin());
        std::cout << _light << std::endl;
		_guiEnv->getSkin()->getColor(irr::gui::EGDC_WINDOW).getAlpha();
    }
}

void	graphic::IrrlichtLib::clearGui() noexcept
{
	_guiEnv->clear();
}

void	graphic::IrrlichtLib::clearScene() noexcept
{
	_sceneManager->clear();
}

irr::gui::IGUIEnvironment *graphic::IrrlichtLib::createNewWindow(size_t posX, size_t posY, size_t width, size_t height)
{
	irr::gui::IGUISkin*mskin= _guiEnv->createSkin(irr::gui::EGST_WINDOWS_CLASSIC);
	irr::video::SColor mcol;
	mcol.set(50,128,128,128);
	mskin->setColor(irr::gui::EGDC_3D_FACE, mcol);
	_guiEnv->setSkin(mskin);
	_guiEnv->addWindow(irr::core::rect<irr::s32>(posX, posY, width, height), false, L"Inventary");
	return (_guiEnv);
}