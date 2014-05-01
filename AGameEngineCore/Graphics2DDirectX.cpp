#include "Graphics2DDirectX.h"


Graphics2DDirectX::Graphics2DDirectX(void)
{
}


Graphics2DDirectX::~Graphics2DDirectX(void)
{
}

void Graphics2DDirectX::LoadTexture(string textureName)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Graphics2DDirectX::Draw()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Graphics2DDirectX::CreateTexture(
	_In_ bool decodeAsDDS,
	_In_reads_bytes_(dataSize) byte* data,
	_In_ uint32 dataSize,
	_Out_opt_ ID3D11Texture2D** texture,
	_Out_opt_ ID3D11ShaderResourceView** textureView,
	_In_opt_ Platform::String^ debugName
	)
{
	ComPtr<ID3D11ShaderResourceView> shaderResourceView;
	ComPtr<ID3D11Texture2D> texture2D;

	if (decodeAsDDS)
	{
		ComPtr<ID3D11Resource> resource;

		if (textureView == nullptr)
		{
			CreateDDSTextureFromMemory(
				m_d3dDevice.Get(),
				data,
				dataSize,
				&resource,
				nullptr
				);
		}
		else
		{
			CreateDDSTextureFromMemory(
				m_d3dDevice.Get(),
				data,
				dataSize,
				&resource,
				&shaderResourceView
				);
		}

		DX::ThrowIfFailed(
			resource.As(&texture2D)
			);
	}
	else
	{
		if (m_wicFactory.Get() == nullptr)
		{
			// A WIC factory object is required in order to load texture
			// assets stored in non-DDS formats.  If BasicLoader was not
			// initialized with one, create one as needed.
			DX::ThrowIfFailed(
				CoCreateInstance(
				CLSID_WICImagingFactory,
				nullptr,
				CLSCTX_INPROC_SERVER,
				IID_PPV_ARGS(&m_wicFactory)
				)
				);
		}

		ComPtr<IWICStream> stream;
		DX::ThrowIfFailed(
			m_wicFactory->CreateStream(&stream)
			);

		DX::ThrowIfFailed(
			stream->InitializeFromMemory(
			data,
			dataSize
			)
			);

		ComPtr<IWICBitmapDecoder> bitmapDecoder;
		DX::ThrowIfFailed(
			m_wicFactory->CreateDecoderFromStream(
			stream.Get(),
			nullptr,
			WICDecodeMetadataCacheOnDemand,
			&bitmapDecoder
			)
			);

		ComPtr<IWICBitmapFrameDecode> bitmapFrame;
		DX::ThrowIfFailed(
			bitmapDecoder->GetFrame(0, &bitmapFrame)
			);

		ComPtr<IWICFormatConverter> formatConverter;
		DX::ThrowIfFailed(
			m_wicFactory->CreateFormatConverter(&formatConverter)
			);

		DX::ThrowIfFailed(
			formatConverter->Initialize(
			bitmapFrame.Get(),
			GUID_WICPixelFormat32bppPBGRA,
			WICBitmapDitherTypeNone,
			nullptr,
			0.0,
			WICBitmapPaletteTypeCustom
			)
			);

		uint32 width;
		uint32 height;
		DX::ThrowIfFailed(
			bitmapFrame->GetSize(&width, &height)
			);

		std::unique_ptr<byte[]> bitmapPixels(new byte[width * height * 4]);
		DX::ThrowIfFailed(
			formatConverter->CopyPixels(
			nullptr,
			width * 4,
			width * height * 4,
			bitmapPixels.get()
			)
			);

		D3D11_SUBRESOURCE_DATA initialData;
		ZeroMemory(&initialData, sizeof(initialData));
		initialData.pSysMem = bitmapPixels.get();
		initialData.SysMemPitch = width * 4;
		initialData.SysMemSlicePitch = 0;

		CD3D11_TEXTURE2D_DESC textureDesc(
			DXGI_FORMAT_B8G8R8A8_UNORM,
			width,
			height,
			1,
			1
			);

		DX::ThrowIfFailed(
			m_d3dDevice->CreateTexture2D(
			&textureDesc,
			&initialData,
			&texture2D
			)
			);

		if (textureView != nullptr)
		{
			CD3D11_SHADER_RESOURCE_VIEW_DESC shaderResourceViewDesc(
				texture2D.Get(),
				D3D11_SRV_DIMENSION_TEXTURE2D
				);

			DX::ThrowIfFailed(
				m_d3dDevice->CreateShaderResourceView(
				texture2D.Get(),
				&shaderResourceViewDesc,
				&shaderResourceView
				)
				);
		}
	}

	if (texture != nullptr)
	{
		*texture = texture2D.Detach();
	}
	if (textureView != nullptr)
	{
		*textureView = shaderResourceView.Detach();
	}
}