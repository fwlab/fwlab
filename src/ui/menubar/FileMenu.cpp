#include <fstream>
#include <imgui.h>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include "FileMenu.h"

using namespace rapidjson;

namespace fwlab::ui::menubar
{
	void FileMenu::render()
	{
		if (ImGui::BeginMenu("文件", true))
		{
			if (ImGui::MenuItem("新建", "Ctrl+N", false, true))
			{
			}
			if (ImGui::MenuItem("打开", "Ctrl+O", false, true))
			{
			}
			if (ImGui::MenuItem("保存", "Ctrl+S", false, true))
			{
				// 1. 把 JSON 解析至 DOM。
				const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
				Document d;
				d.Parse(json);

				// 2. 利用 DOM 作出修改。
				Value& s = d["stars"];
				s.SetInt(s.GetInt() + 1);

				// 3. 把 DOM 转换（stringify）成 JSON。
				StringBuffer buffer;
				Writer<StringBuffer> writer(buffer);
				d.Accept(writer);

				// Output {"project":"rapidjson","stars":11}
				std::ofstream out("test.txt");
				out << buffer.GetString() << std::endl;
				out.close();
			}
			if (ImGui::MenuItem("另存为...", nullptr, false, true))
			{
			}
			if (ImGui::MenuItem("关闭", nullptr, false, true))
			{
			}
			ImGui::Separator();
			if (ImGui::MenuItem("退出", "Ctrl+Q", false, true))
			{
			}
			ImGui::EndMenu();
		}
	}
}