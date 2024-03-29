/*
*Jeesoo Kim
*Class Project
*CS200
*Fall 2019
*/
#include "Component_Sprite.hpp"
#include "angles.hpp"
#include "Mesh.hpp"
#include <GL/glew.h>
#include "StockShaders.hpp"
#include "Graphic.hpp"
#include "Object.hpp"


bool Sprite::Can_Load_To_Texture(Texture& n_texture, const char* file_path)
{
	const bool is_okay = n_texture.LoadFromPNG(file_path);
	if (!is_okay)
	{
		//std::cerr << "Failed to load \"" << file_path << "\"\n";
	}
	return is_okay;
}

void Sprite::Init(Object* obj)
{
	m_owner = obj;

	m_owner->Set_Center({ m_owner->GetTransform().GetTranslation().x , m_owner->GetTransform().GetTranslation().y });

}
Mesh Sprite::Helper_make_mesh(ObjectShape objShape, vector2<float> scale, Color4ub color)
{
	Mesh newMesh;
	if (objShape == ObjectShape::SQUARE)
	{
		newMesh = MESH::create_box(scale.x, color);
	}
	else if (objShape == ObjectShape::RECT)
	{
		newMesh = MESH::create_rectangle(scale.x, scale.y, color);
	}
	else if (objShape == ObjectShape::CIRCLE)
	{
		newMesh = MESH::create_circle(scale.x, color);
	}
	else if (objShape == ObjectShape::ELLIPSE)
	{
		newMesh = MESH::create_ellipse(scale.x, color);
	}
	else if (objShape == ObjectShape::TRIANGLE)
	{
		newMesh = MESH::create_triangle(scale, color);
	}
	else if (objShape == ObjectShape::QUAD)
	{
		vector2<float> point_1 = { -scale.x, -scale.y / 2 };
		vector2<float> point_2 = { 0, scale.y / 2 };
		vector2<float> point_3 = { scale.x, scale.y / 2 };
		vector2<float> point_4 = { 0, -scale.y / 2 };
		newMesh = MESH::create_quad(point_1, point_2, point_3, point_4, color);
	}
	else
	{
		newMesh = MESH::create_line({ 0,0 }, { 1,0 }, scale, color);
	}
	return newMesh;
}

Sprite::Sprite(Object* obj, ObjectShape objShape, vector2<float> position, vector2<float> scale, Color4ub color)
{
	m_owner = obj;
	float zoom = Graphic::GetGraphic()->GetView().GetCameraView().GetZoom();
	material.shader = &(SHADER::solid_color());
	material.color4fUniforms["color"] = to_color4f(color);
	material.matrix3Uniforms["to_ndc"] = MATRIX3::build_scale(2.0f / width * zoom, 2.0f / height * zoom);

	Mesh newMesh = Helper_make_mesh(objShape, scale, color);
	shape.InitializeWithMeshAndLayout(newMesh, SHADER::solid_color_vertex_layout());
	m_owner->SetMesh(newMesh);

	m_owner->Get_Object_Points() = m_owner->GetMesh().Get_Points();
	m_owner->SetTranslation(position);
	m_owner->Set_Center({ position.x , position.y });

	Graphic::GetGraphic()->get_need_update_sprite() = true;
}

Sprite::Sprite(Object* obj, ObjectManager* obj_mang, ObjectShape objShape, bool is_hierarchy, const char* staticSpritePath, vector2<float> position, vector2<float> scale, Color4ub color)
{
	m_owner = obj;

	const auto path = staticSpritePath;
	material.shader = &(SHADER::textured());
	if (!Can_Load_To_Texture(texture, path))
	{

	}
	texture.SelectTextureForSlot(texture);
	material.textureUniforms["texture_to_sample"] = { &(texture) };
	material.color4fUniforms["color"] = { 1.0f };

	Mesh newMesh = Helper_make_mesh(objShape, scale, color);
	shape.InitializeWithMeshAndLayout(newMesh, SHADER::textured_vertex_layout());

	m_owner->SetMesh(newMesh);
	m_owner->Get_Object_Points() = m_owner->GetMesh().Get_Points();
	m_owner->SetTranslation(position);
	m_owner->Set_Center({ position.x , position.y });

	float zoom = Graphic::GetGraphic()->GetView().GetCameraView().GetZoom();
	matrix3<float> mat_ndc = Graphic::GetGraphic()->GetView().GetCameraView().GetCameraToNDCTransform();
	mat_ndc *= Graphic::GetGraphic()->GetView().GetCamera().WorldToCamera();
	mat_ndc *= m_owner->GetTransform().GetModelToWorld();

	material.matrix3Uniforms["to_ndc"] = mat_ndc * MATRIX3::build_scale(2.0f / Get_Width() * zoom, 2.0f / Get_Height() * zoom);

	if (is_hierarchy)
	{
		Object* health_bar = new Object(false);

		health_bar->GetMesh().Get_Is_Moved() = true;

		vector2<float> hp_position = { m_owner->GetTransform().GetTranslation().x, m_owner->GetTransform().GetTranslation().y + 120 };

		health_bar->Set_Tag("arena");
		health_bar->AddComponent(new Sprite(health_bar, ObjectShape::RECT, hp_position, { 150,30 }, { 0,255,0,255 }));

		m_owner->Get_Child().push_back(health_bar);
		obj_mang->AddObject(health_bar);
	}

}

Sprite::Sprite(Object* obj, ObjectShape objShape, const char* staticSpritePath, vector2<float> position, vector2<float> scale, Color4ub color)
{
	m_owner = obj;

	const auto path = staticSpritePath;
	material.shader = &(SHADER::textured());
	if (!Can_Load_To_Texture(texture, path))
	{

	}
	texture.SelectTextureForSlot(texture);
	material.textureUniforms["texture_to_sample"] = { &(texture) };
	material.color4fUniforms["color"] = { 1.0f };

	Mesh newMesh = Helper_make_mesh(objShape, scale, color);
	shape.InitializeWithMeshAndLayout(newMesh, SHADER::textured_vertex_layout());

	m_owner->SetMesh(newMesh);
	m_owner->Get_Object_Points() = m_owner->GetMesh().Get_Points();
	m_owner->SetTranslation(position);
	m_owner->Set_Center({ position.x , position.y });

	float zoom = Graphic::GetGraphic()->GetView().GetCameraView().GetZoom();
	matrix3<float> mat_ndc = Graphic::GetGraphic()->GetView().GetCameraView().GetCameraToNDCTransform();
	mat_ndc *= Graphic::GetGraphic()->GetView().GetCamera().WorldToCamera();
	mat_ndc *= m_owner->GetTransform().GetModelToWorld();

	material.matrix3Uniforms["to_ndc"] = mat_ndc * MATRIX3::build_scale(2.0f / Get_Width() * zoom, 2.0f / Get_Height() * zoom);

}

Sprite::Sprite(Object* obj, const char* aniamtedSpritePath, bool animated, int frames, float m_speed, vector2<float> position, vector2<float> scale, Color4ub color)
{
	m_owner = obj;
	is_animated = animated;
	frame = frames;
	const auto path = aniamtedSpritePath;
	material.shader = &(SHADER::textured());
	if (!Can_Load_To_Texture(texture, path))
	{

	}
	texture.SelectTextureForSlot(texture);
	material.textureUniforms["texture_to_sample"] = { &(texture) };
	material.color4fUniforms["color"] = to_color4f(color);

	Mesh square;
	square = MESH::create_box(scale.x, { 100,100,100,255 });
	shape.InitializeWithMeshAndLayout(square, SHADER::textured_vertex_layout());

	m_owner->SetMesh(square);

	m_owner->GetMesh().ClearTextureCoordinates();
	m_owner->GetMesh().AddTextureCoordinate({ spriteWidth , 1 });
	m_owner->GetMesh().AddTextureCoordinate({ spriteWidth , 0 });
	spriteWidth += float(1.0 / frame);
	m_owner->GetMesh().AddTextureCoordinate({ spriteWidth , 0 });
	m_owner->GetMesh().AddTextureCoordinate({ spriteWidth , 1 });

	m_owner->Get_Object_Points() = m_owner->GetMesh().Get_Points();
	m_owner->SetTranslation(position);
	m_owner->Set_Center({ position.x , position.y });
	speed = m_speed;
	matrix3<float> mat_ndc = Graphic::GetGraphic()->GetView().GetCameraView().GetCameraToNDCTransform();
	mat_ndc *= Graphic::GetGraphic()->GetView().GetCamera().WorldToCamera();
	mat_ndc *= m_owner->GetTransform().GetModelToWorld();

	material.matrix3Uniforms["to_ndc"] = mat_ndc * MATRIX3::build_scale(2.0f / Get_Width(), 2.0f / Get_Height());

	material.floatUniforms["time"] = 1;
}

void Sprite::Update(float dt)
{
	shape.UpdateVerticesFromMesh(m_owner->GetMesh());

	material.floatUniforms["time"] -= dt * speed;
	if (is_animated && material.floatUniforms["time"] <= 0)
	{
		m_owner->GetMesh().ClearTextureCoordinates();
		if (spriteWidth <= 1)
		{
			m_owner->GetMesh().AddTextureCoordinate({ spriteWidth , 1 });
			m_owner->GetMesh().AddTextureCoordinate({ spriteWidth , 0 });
			spriteWidth += float(1.0 / frame);
		}
		else
		{
			spriteWidth = 0;
			m_owner->GetMesh().AddTextureCoordinate({ spriteWidth , 1 });
			m_owner->GetMesh().AddTextureCoordinate({ spriteWidth , 0 });
			spriteWidth += float(1.0 / frame);
		}
		m_owner->GetMesh().AddTextureCoordinate({ spriteWidth , 0 });
		m_owner->GetMesh().AddTextureCoordinate({ spriteWidth , 1 });
		m_owner->SetMesh(m_owner->GetMesh());
		shape.UpdateVerticesFromMesh(m_owner->GetMesh());

		matrix3<float> mat_ndc = Graphic::GetGraphic()->GetView().GetCameraView().GetCameraToNDCTransform();
		mat_ndc *= Graphic::GetGraphic()->GetView().GetCamera().WorldToCamera();
		mat_ndc *= m_owner->GetTransform().GetModelToWorld();

		m_owner->GetMesh().Get_Is_Moved() = false;
		material.matrix3Uniforms["to_ndc"] = mat_ndc;
		material.floatUniforms["time"] = 1;
		Graphic::GetGraphic()->Draw(shape, material);
	}
	if (!is_animated && m_owner->GetMesh().Get_Is_Moved() || Graphic::GetGraphic()->get_need_update_sprite() || m_owner->Get_Tag() == "arena" || m_owner->Get_Tag() == "pipe1" || m_owner->Get_Tag() == "pipe2" || m_owner->Get_Tag() == "pipe3")
	{
		matrix3<float> mat_ndc = Graphic::GetGraphic()->GetView().GetCameraView().GetCameraToNDCTransform();
		mat_ndc *= Graphic::GetGraphic()->GetView().GetCamera().WorldToCamera();
		mat_ndc *= m_owner->GetTransform().GetModelToWorld();

		m_owner->GetMesh().Get_Is_Moved() = false;
		material.matrix3Uniforms["to_ndc"] = mat_ndc;

		Graphic::GetGraphic()->Draw(shape, material);
		if (!m_owner->Get_Child().empty())
		{
			int size = static_cast<int>(m_owner->Get_Child().size());
			for (int i = 0; i < size; i++)
			{

				if (m_owner->Get_Child()[i]->GetComponentByTemplate<Sprite>() != nullptr)
				{
					Object* obj = m_owner->Get_Child()[i];
					obj->GetTransform().GetTranslation_Reference() = m_owner->GetTransform().GetTranslation();

					matrix3<float> transform_mat = mat_ndc * MATRIX3::build_translation(0.0f, 120.0f);
					obj->GetComponentByTemplate<Sprite>()->Get_Material().matrix3Uniforms["to_ndc"] = transform_mat;
					Graphic::GetGraphic()->Draw(obj->GetComponentByTemplate<Sprite>()->Get_Shape(),
						obj->GetComponentByTemplate<Sprite>()->Get_Material());
				}
			}
		}
	}
}