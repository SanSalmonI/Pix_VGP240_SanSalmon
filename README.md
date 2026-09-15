# Pix — Scriptable Software 3D Rasterizer

A C++ software 3D rasterizer with its own script editor, built for the VGP240 3D Graphics and Applications class. It renders 3D scenes entirely in software (CPU-side rasterization, clipping, depth buffering, lighting) driven by a custom `.pix` scripting language, inside an ImGui-based editor.

## What it does

- Provides a **text editor** (with syntax highlighting for the `.pix` language) where you write scene scripts, and a **render viewport** that shows the rasterized output when a script is run.
- Interprets `.pix` scripts through a `ScriptParser` and `CommandDictionary`, which map script keywords (e.g. `SetResolution`, `BeginDraw`, `Vertex`, `PushRotationY`, `SetCameraPosition`, `AddDirectionalLight`) to command objects that drive the rasterizer.
- Implements the rasterization pipeline itself: `Rasterizer`, `Clipper`, `DepthBuffer`, `MatrixStack`, `Camera`, `LightManager`, `MaterialManager`, `ModelManager`.

### Script (`.pix`) capabilities

Based on the registered commands:
- **Setup**: set resolution, viewport, toggle viewport visibility, enable/disable clipping and depth testing.
- **Variables**: float and bool script variables (`$name`).
- **Drawing**: begin/end draw blocks, add vertices, draw pixels, set fill mode, set cull mode, set shade mode, load models.
- **Transforms**: push translation/rotation (X/Y/Z)/scaling onto a matrix stack, pop matrix.
- **Camera**: set position, direction, near/far planes, field of view.
- **Materials**: emissive, ambient, diffuse, specular, shininess.
- **Lights**: ambient/diffuse/specular light color, directional lights, point lights, spot lights.

Sample scripts are in `Pix/Pix/Scripts/` (e.g. `cube.pix`, `3d_lighting.pix`, `3d_directional_light.pix`, `3d_point_light.pix`, `3d_spot_light.pix`, `3d_pipeline.pix`).

## Project Structure

- `Pix/Pix/` — the rasterizer and editor application (`PixEditor`, `TextEditor`, `ScriptParser`, `CommandDictionary`, `Cmd*` command classes, `Rasterizer`, `Clipper`, `DepthBuffer`, `MatrixStack`, `Camera`, `LightManager`, `MaterialManager`, `ModelManager`, `WinMain.cpp` entry point).
- `Pix/X/` — a reusable DirectX-based engine layer (graphics, input, audio, fonts, textures, sprite rendering, ImGui integration) that the Pix app is built on top of.
- `Pix/Assets/` — editor images (logo, about screen).
- `Pix/packages/` — third-party NuGet packages.
- `Pix/X.sln` — Visual Studio solution.

## Running

Open `Pix/X.sln` in Visual Studio (Windows, DirectX) and build/run the `Pix` project.
