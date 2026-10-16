// alvrxr testing: the two d3d11.h C++ helpers hello_xr uses that mingw-w64's d3d11.h lacks.
#pragma once
#ifdef __cplusplus
#include <d3d11.h>
struct CD3D11_VIEWPORT : public D3D11_VIEWPORT {
    CD3D11_VIEWPORT(FLOAT x, FLOAT y, FLOAT w, FLOAT h, FLOAT minDepth = 0.0f, FLOAT maxDepth = 1.0f) {
        TopLeftX = x; TopLeftY = y; Width = w; Height = h; MinDepth = minDepth; MaxDepth = maxDepth;
    }
};
struct CD3D11_DEPTH_STENCIL_VIEW_DESC : public D3D11_DEPTH_STENCIL_VIEW_DESC {
    CD3D11_DEPTH_STENCIL_VIEW_DESC(D3D11_DSV_DIMENSION dim, DXGI_FORMAT format = DXGI_FORMAT_UNKNOWN, UINT mip = 0,
                                   UINT firstSlice = 0, UINT arraySize = (UINT)-1, UINT flags = 0) {
        Format = format; ViewDimension = dim; Flags = flags;
        switch (dim) {
        case D3D11_DSV_DIMENSION_TEXTURE2DARRAY:
            Texture2DArray.MipSlice = mip; Texture2DArray.FirstArraySlice = firstSlice; Texture2DArray.ArraySize = arraySize; break;
        case D3D11_DSV_DIMENSION_TEXTURE2DMSARRAY:
            Texture2DMSArray.FirstArraySlice = firstSlice; Texture2DMSArray.ArraySize = arraySize; break;
        default: Texture2D.MipSlice = mip; break;
        }
    }
};
#endif
