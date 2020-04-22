// �s�N�Z���V�F�[�_�[�̓���
struct PS_INPUT
{
    float4 DiffuseColor : COLOR0;
    float4 SpecularColor : COLOR1;
    float2 TextureCoord0 : TEXCOORD0;
    float2 TextureCoord1 : TEXCOORD1;
};

// �s�N�Z���V�F�[�_�[�̏o��
struct PS_OUTPUT
{
    float4 Output : COLOR0;
};


// C++ ���Őݒ肷��萔�̒�`

// �`�悷��e�N�X�`��
sampler DiffuseMapTexture : register(s0);


// main�֐�
PS_OUTPUT main(PS_INPUT PSInput)
{
    PS_OUTPUT PSOutput;
    float4 lTextureColor;

    // �e�N�X�`���[�̐F���擾
    lTextureColor = tex2D(DiffuseMapTexture, PSInput.TextureCoord0);

    // �o�͂���F�͐����ƐԐ������t�]��������
    PSOutput.Output.r = lTextureColor.b;
    PSOutput.Output.g = lTextureColor.g;
    PSOutput.Output.b = lTextureColor.r;
    PSOutput.Output.a = lTextureColor.a;

    // �֐��̖߂�l�����X�^���C�U�ɓn�����
    return PSOutput;
}