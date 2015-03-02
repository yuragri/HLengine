#include "Sprite.h"

namespace HotLine
{
	//shitty class for inside use
	class Grid
	{
	public:
		Grid(ID3D11Device* device);
		Grid();
		~Grid();
		bool visible;
		void Draw(ID3D11DeviceContext* context, XMMATRIX& viewProj);
	private:
		ID3D11ShaderResourceView* mCubeMapSRV2;
		Sprite* sprites[52];
	};
}
