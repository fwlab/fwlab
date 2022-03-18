#include <imgui.h>
#include <AIS_Shape.hxx>
#include <BRepPrimAPI_MakeBox.hxx>
#include "ObjectMenu.h"

namespace fwlab::ui::menubar
{
	void ObjectMenu::render()
	{
		if (ImGui::BeginMenu("物体", true))
		{
			if (ImGui::BeginMenu("几何体", true))
			{
				if (ImGui::MenuItem("平面", nullptr, false, true))
				{
					addPlane();
				}
				if (ImGui::MenuItem("正方体", nullptr, false, true))
				{
				}
				if (ImGui::MenuItem("球体", nullptr, false, true))
				{
				}
				if (ImGui::MenuItem("圆柱体", nullptr, false, true))
				{
				}
				if (ImGui::MenuItem("圆锥体", nullptr, false, true))
				{
				}
				ImGui::EndMenu();
			}

			if (ImGui::BeginMenu("文字", true))
			{
				if (ImGui::MenuItem("不缩放文字", nullptr, false, true))
				{
				}
				if (ImGui::MenuItem("三维文字", nullptr, false, true))
				{
				}
				ImGui::EndMenu();
			}

			if (ImGui::BeginMenu("曲线", true))
			{
				if (ImGui::MenuItem("线段", nullptr, false, true))
				{
				}
				if (ImGui::MenuItem("贝塞尔曲线", nullptr, false, true))
				{
				}
				if (ImGui::MenuItem("椭圆曲线", nullptr, false, true))
				{
				}
				ImGui::EndMenu();
			}

			if (ImGui::BeginMenu("帮助器", true))
			{
				if (ImGui::MenuItem("箭头帮助器", nullptr, false, true))
				{
				}
				if (ImGui::MenuItem("坐标轴帮助器", nullptr, false, true))
				{
				}
				ImGui::EndMenu();
			}

			ImGui::Separator();

			if (ImGui::MenuItem("精灵"))
			{

			}

			ImGui::EndMenu();
		}
	}

	void ObjectMenu::addPlane()
	{
		BRepPrimAPI_MakeBox box(10., 20., 30.);
		box.Build();
		TopoDS_Solid solid = box.Solid();
		Handle(TopoDS_TShape) shape = solid.TShape();
	}
}
