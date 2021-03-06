#include "app.hpp"
#include "gui.hpp"


namespace rack {

RackScene::RackScene() {
	scrollWidget = new ScrollWidget();
	{
		assert(!gRackWidget);
		gRackWidget = new RackWidget();
		scrollWidget->container->addChild(gRackWidget);
	}
	addChild(scrollWidget);

	toolbar = new Toolbar();
	addChild(toolbar);
	scrollWidget->box.pos.y = toolbar->box.size.y;
}

void RackScene::step() {
	toolbar->box.size.x = box.size.x;
	scrollWidget->box.size = box.size.minus(scrollWidget->box.pos);

	Scene::step();
}

void RackScene::draw(NVGcontext *vg) {
	Scene::draw(vg);
}


} // namespace rack
