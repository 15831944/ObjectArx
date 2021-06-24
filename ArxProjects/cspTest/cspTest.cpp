// cspTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <windows.h>
#include <WinCrypt.h>

const char* prikey =
"BwIAAAAkAABSU0EyABAAAAEAAQB5zatRWWkeG35I7VcBCImhlxDznQgJI2Y0849u\
SRP753Z7WgfO3AOofmPl2nAu4Pj8xvObWPwYRqwaxuh0jkwwnWmCFULFPJ5kvONf\
TLNDhLCtmudTtSe7yR2QUk2n4WNarNpDx0w4GgKUX4B0Yd31DpFbl2KfhKKMdCTQ\
ocn3T7v7Sa9++4NXdrPNZc2oSLScdIPLck8OCLrvpNrplLxUUL0m/KntwPsiLbaH\
2ynYweGyWSo6a9BPvK6Ip0iiTBo1qNhXWN1M/oXFlakZhXcUQiN9x4Y1Odt9webb\
xFXNySorC8q0oNAVmWbAW9+Cb/kt59Tled+zHz8n0dkiLdGDfFy8jZs6dmLVqeOp\
WTHtcoZrLSJyrLSEFn9nvN16c9PGyj1cqb/qfSqDv6V7ExIgZE5P+tZiu5x0e/NG\
7FJLMVfAXmtHgdAyScJAKk+FpLtC8uYpL9R8fAGfy0TtX7Z4j38Q5gRWK19f0Aba\
ibywsJLygvZcxE1s1oShVCwPdyiT4d4eNEhJxqnCuIWZt4zPI1V/PxJkg+ukRFcU\
GLnxOycl3kYM6x5/A4+1HUN9jMJ3WVONWiE6toHhrXNHW0vHZDPjsSxQMwhMOUoB\
5vvLPoVYTiFMNDMLoQ39h5mVg4FA4n9S4ms7oiOv0qA8LHJpbXeMIn6u+hDTQJzT\
FRZc3AvFdJtNgoOebMtwqh9LKy8MMDrl0Ey3iPnkwPKyxsuLM7M3r9aP/sVEMlCO\
8xXqQ8153saj29CkpP4pBaKxpxN3OcTny12Qpn6HzZWQjPRFPi96kyvMi3eL0hyd\
Lb+wmXxgcFz4QMZLe0jWmYRTmut7qSWaKeExW1tRVrp3RuiNoXVfbotp8BmWnxit\
Ekq3o+ODGjOYXwrQwYdcPRTGPRC0neYI8NtJQMVEgEc/OdHaXcDrY1cd5Zyz6r3q\
fbIRHJBwB7dTuoN84ACZI5KJcxsyWmJ8KlKPDkDiFucJ4GxvltQPGtwe+KBH5OZF\
c51yvdc77hJscotI8MGQDHp4AfsLwh8eLgKCcRmgoqxbFfMCL+wNjIIHe7m6Bvvj\
co64Xuq/6vriQKQIHQ+YsyLuRlWta7moXlC1EFGQQQubQZyRn3HZJvdm573xozkA\
hTlYLCVqh5qEDGCDYJ6r+UOxlOetWq8nZrhx1OerlzIpk0UpnQmHS2gS1Ko6usd4\
RW3MZszuUns2ILDQoP+LFtyAXZeBJDnPbpn6T1W5aA5n2nAZ/0bsyx71pHVP/acH\
GNubDCJBj8MOpPmjXhR7CtClULiUZoNBOQN0XO1he2Mou5dG6iTAKOvO6Fhfs1Rl\
c6tGnArZkX7T2LFyB73+AqBKjQShMH4Z2lU/YvlF2KEnhL7gUSaW+M6PQpe2Z1Zk\
m0O21RAYU6neWilv327FlC5Hxa+wLsBj3d++Btk+rC1KB2a6i/irkBDtN9XC7Eea\
zznRy9G4wpzI8GkGunCwL6wC+eTo/FH2axmffI3gSsZuSS26VRxmKsdXXIWWToww\
PtY3RZe2WZuot8ERRKyjWDm1EgA/3CubLHhdPH6nEan/X3xBPjfcqROlSuw17rlr\
Ic1CA5rJBW9AQt92GfubzpyWVO4xx35PJATdhwGWr5UDFBlT/+aoTGsz0e4A0fPG\
tKJPPbmPUevJHA/l1+/x12YhogpEkpRlfWppC+VbzNK6DzixQyga5Qs2G9baF04j\
A/EIMg825+pRQoTrSsPk8IYobRDoqT+tBNnGHrCS2J92X9V8M6yZlOJ6rYNO4HXD\
OyxWc45WcSv7j/joXFG0RB5CTePwHDvoMtQOOgUrVwhoKPWAruuMWgo0SsPtAAcX\
+Vp5fBGRTQUm/Q9A8FIZ1Q1XNVIXXQW2luC30/X9GmdvVJ+/H6Zbr5TPY9r1VnF7\
vps0/Hsqn+EGzPBfgdEqxD61g3avpW2jkLq68s61SVK1tMKFHgj4tS77iR1BRRTK\
E/UHFUquC8tX2Qj4mjFZDN6NCsV3c8YcPub5Xzv4hMToR6QTyaeg1ognC0YGbBIq\
uadoh4KHMaWneDKeW1CmCcSGINun96BWbrHXkI9hk1nII9ymvYM8b41aSm+CGb24\
cfY1CiJICYPRG+N0l0zJ6yozaTTbF6XTl73wCWLl9FuWIbv9KHyp6pVDdHWt76aC\
ZeUuZzedu3bOQki8qpdl8pqHgec/Q+XDcBlFl7ZsgdfnunLjuwnD8Kq/N9NnOORq\
Qfefjt0d+glKUQd9ISWvlUCq6TGFCIm2JbtBvMXnrKJ4/A/EuyWg2GZJbVlp+1Lj\
W05vrHQaJUeXMwWHbW+pstnKJLGOG4Ph1nmJrBIJWPrgtVbt86hh7GtJYQO/HAba\
dHcpD/r7sziE5ANUTpqnyol6Vq7V8Pek4UIglFDcvkwR37k/aYPian4sYLUHMy8Q\
vaJ5yAfhRm4vdU6RNtxua8uXCtoAUXyQ1OUOdox7SeTPLvnpKO44oj7lj2FLv/ZY\
yxuAYaCe9LuuuKTkJ5Shzb4PWbdKRwW0m8EDlwzl7OwDqdhp4oxpXXJ6iDS2DNQS\
4dSkiDwsL7l/HjW/SmRHawqUeyvttg94mReA0zEjtxvEni21jFikAtUj7bu3QRvN\
DzPGS+sgkblg0VCFdaOLrUCmo8uSasApgo9Kw8zT7e93+IrTG5kAVqnLauMBlMYr\
11kMIrYyI5ba/ReeeVCP3UWmz09f7Eo5ve0W0qhiRMzqH0+oszyXs5D5XSqSNKPA\
pK7jvDqPRGJyyZy20bcvErXrWoFZlDDnnyDEoLkP6RwuqT+2sWGNjXRNMusTuBjJ\
vUvARC6fbMIqmLGOGfahfKU3o2JJC7+VeiFDA6YI97kEo5QRcIWh9esfwopNjy+F\
5ZPkFQXuVc7eU8LWHW69WNWHMWpOYIT1mRn3sHN0KY6q/+zpSpTdsJL6W8RKCzS7\
jaYFEusTCh8isCzSFlHO7pyTDel7IJVT582iNpxMh8MFFH6kh2twaaZpjeZCmhId\
b+In2PGzByna/hPCnYWMo1lPAXnsn/zopNnrlgNHRISoyivtEOSa9Xt3CTuNF6a4\
EL3uEQkVeWCAqu0hsCBPQe0ZjHE=";
const char* pubkey =
"MIICIjANBgkqhkiG9w0BAQEFAAOCAg8AMIICCgKCAgEA3FwWFdOcQNMQ+q5+Iox3\
bWlyLDyg0q8jojtr4lJ/4kCBg5WZh/0NoQszNEwhTliFPsv75gFKOUwIM1AsseMz\
ZMdLW0dzreGBtjohWo1TWXfCjH1DHbWPA38e6wxG3iUnO/G5GBRXRKTrg2QSP39V\
I8+Mt5mFuMKpxklINB7e4ZModw8sVKGE1mxNxFz2gvKSsLC8idoG0F9fK1YE5hB/\
j3i2X+1Ey58BfHzULynm8kK7pIVPKkDCSTLQgUdrXsBXMUtS7Ebze3Scu2LW+k9O\
ZCASE3ulv4Mqfeq/qVw9ysbTc3rdvGd/FoS0rHIiLWuGcu0xWanjqdVidjqbjbxc\
fIPRLSLZ0Sc/H7PfeeXU5y35b4LfW8BmmRXQoLTKCysqyc1VxNvmwX3bOTWGx30j\
QhR3hRmplcWF/kzdWFfYqDUaTKJIp4iuvE/QazoqWbLhwdgp24e2LSL7wO2p/Ca9\
UFS8lOnapO+6CA5PcsuDdJy0SKjNZc2zdleD+36vSfu7T/fJodAkdIyihJ9il1uR\
DvXdYXSAX5QCGjhMx0ParFpj4adNUpAdybsntVPnmq2whEOzTF/jvGSePMVCFYJp\
nTBMjnToxhqsRhj8WJvzxvz44C5w2uVjfqgD3M4HWnt25/sTSW6P8zRmIwkInfMQ\
l6GJCAFX7Uh+Gx5pWVGrzXkCAwEAAQ==";
int outKey()
{
	std::cout << "开始" << std::endl;
	HCRYPTPROV hProv = NULL;
	HCRYPTKEY hKey = NULL;
	if (!CryptAcquireContextA(&hProv, "Zwsoft", NULL, PROV_RSA_AES, 0))
	{
		DWORD err = GetLastError();
		std::cout << "获取容器失败：" << err << std::endl;
		if (!CryptAcquireContextA(&hProv, "Zwsoft", NULL, PROV_RSA_AES, CRYPT_DELETEKEYSET))
		{
			DWORD err = GetLastError();
			std::cout << "删除失败：" << err << std::endl;
		}
		if (!CryptAcquireContextA(&hProv, "Zwsoft", NULL, PROV_RSA_AES, CRYPT_NEWKEYSET))
		{
			DWORD err = GetLastError();
			err = GetLastError();
			std::cout << "生成容器失败：" << err << std::endl;
			getchar();
			return -1;
		}
	}
	if (!CryptGenKey(hProv, AT_SIGNATURE, CRYPT_EXPORTABLE|0x10000000, &hKey))
	{
		DWORD err = GetLastError();
		std::cout << "生成密钥失败：" << err << std::endl;
		getchar();
		return -1;
	}
	DWORD len = 0;
	if (!CryptExportKey(hKey, NULL, PRIVATEKEYBLOB, 0, NULL, &len))
	{
		DWORD err = GetLastError();
		std::cout << "得到密钥长度失败：" << err << std::endl;
		getchar();
		return -1;
	}
	BYTE *keyOrg = new BYTE[len + 1];
	if (!CryptExportKey(hKey, NULL, PRIVATEKEYBLOB, 0, keyOrg, &len))
	{
		delete[]keyOrg;
		DWORD err = GetLastError();
		std::cout << "导出密钥失败：" << err << std::endl;
		getchar();
		return -1;
	}
	DWORD len2 = 0;
	if (!CryptBinaryToStringA(keyOrg, len, CRYPT_STRING_BASE64_ANY, NULL, &len2))
	{
		delete[]keyOrg;
		DWORD err = GetLastError();
		std::cout << "得到编码长度失败：" << err << std::endl;
		getchar();
		return -1;
	}
	char* out = new char[len2 + 1];
	if (!CryptBinaryToStringA(keyOrg, len, CRYPT_STRING_BASE64_ANY, out, &len2))
	{
		delete[]keyOrg;
		delete[]out;
		DWORD err = GetLastError();
		std::cout << "base64编码失败：" << err << std::endl;
		getchar();
		return -1;
	}
	std::cout << out << std::endl;
	delete[]keyOrg;
	delete[]out;
	keyOrg = NULL;
	out = NULL;
	if (!CryptExportPublicKeyInfo(hProv, AT_SIGNATURE, X509_ASN_ENCODING, NULL, &len))
	{
		DWORD err = GetLastError();
		std::cout << "得到公钥长度失败：" << err << std::endl;
		getchar();
		return -1;
	}
	CERT_PUBLIC_KEY_INFO *pinfo = (CERT_PUBLIC_KEY_INFO*)malloc(len+1);
	if (!CryptExportPublicKeyInfo(hProv, AT_SIGNATURE, X509_ASN_ENCODING, pinfo, &len))
	{
		DWORD err = GetLastError();
		std::cout << "导出公钥失败：" << err << std::endl;
		getchar();
		return -1;
	}
	if (!CryptEncodeObjectEx((X509_ASN_ENCODING | PKCS_7_ASN_ENCODING), X509_PUBLIC_KEY_INFO, pinfo, 0, NULL, NULL, &len))
	{
		free(pinfo);
		DWORD err = GetLastError();
		std::cout << "得到公钥编码长度失败：" << err << std::endl;
		getchar();
		return -1;
	}
	keyOrg = new BYTE[len + 1];
	if (!CryptEncodeObjectEx((X509_ASN_ENCODING | PKCS_7_ASN_ENCODING), X509_PUBLIC_KEY_INFO, pinfo, 0, NULL, keyOrg, &len))
	{
		free(pinfo);
		DWORD err = GetLastError();
		std::cout << "公钥编码失败：" << err << std::endl;
		getchar();
		return -1;
	}
	free(pinfo);
	pinfo = NULL;
	if (!CryptBinaryToStringA(keyOrg, len, CRYPT_STRING_BASE64_ANY, NULL, &len2))
	{
		delete[]keyOrg;
		DWORD err = GetLastError();
		std::cout << "得到编码长度2失败：" << err << std::endl;
		getchar();
		return -1;
	}
	out = new char[len2 + 1];
	if (!CryptBinaryToStringA(keyOrg, len, CRYPT_STRING_BASE64_ANY, out, &len2))
	{
		delete[]keyOrg;
		delete[]out;
		DWORD err = GetLastError();
		std::cout << "base64编码2失败：" << err << std::endl;
		getchar();
		return -1;
	}
	std::cout << out << std::endl;
	delete[]keyOrg;
	delete[]out;
	keyOrg = NULL;
	out = NULL;
	std::cout << "结束" << std::endl;
	return 0;
}

int main()
{
	std::cout << "开始" << std::endl;
	HCRYPTPROV hProv = NULL;
	HCRYPTKEY hKey1 = NULL;
	HCRYPTKEY hKey2 = NULL;
	bool a = false;
	if (!CryptAcquireContextA(&hProv, "Zwsoft", NULL, PROV_RSA_AES, 0))
	{
		DWORD err = GetLastError();
		std::cout << "获取容器失败：" << err << std::endl;
		if (!CryptAcquireContextA(&hProv, "Zwsoft", NULL, PROV_RSA_AES, CRYPT_DELETEKEYSET))
		{
			DWORD err = GetLastError();
			std::cout << "删除失败：" << err << std::endl;
		}
		if (!CryptAcquireContextA(&hProv, "Zwsoft", NULL, PROV_RSA_AES, CRYPT_NEWKEYSET))
		{
			DWORD err = GetLastError();
			err = GetLastError();
			std::cout << "生成容器失败：" << err << std::endl;
			a = true;
		}
	}
	if (a && !CryptAcquireContextA(&hProv, "Zwsoft1", NULL, PROV_RSA_AES, 0))
	{
		DWORD err = GetLastError();
		std::cout << "获取容器失败1：" << err << std::endl;
		if (!CryptAcquireContextA(&hProv, "Zwsoft1", NULL, PROV_RSA_AES, CRYPT_DELETEKEYSET))
		{
			DWORD err = GetLastError();
			std::cout << "删除失败1：" << err << std::endl;
		}
		if (!CryptAcquireContextA(&hProv, "Zwsoft1", NULL, PROV_RSA_AES, CRYPT_NEWKEYSET))
		{
			DWORD err = GetLastError();
			err = GetLastError();
			std::cout << "生成容器失败1：" << err << std::endl;
			getchar();
			return -1;
		}
	}
	DWORD len = 0;
	if (!CryptStringToBinaryA(prikey, strlen(prikey), CRYPT_STRING_BASE64_ANY, NULL, &len, NULL, NULL))
	{
		DWORD err = GetLastError();
		std::cout << "得到解码长度失败：" << err << std::endl;
		getchar();
		return -1;
	}
	BYTE* out = new BYTE[len + 1];
	if (!CryptStringToBinaryA(prikey, strlen(prikey), CRYPT_STRING_BASE64_ANY, out, &len, NULL, NULL))
	{
		delete[]out;
		DWORD err = GetLastError();
		std::cout << "base64解码失败：" << err << std::endl;
		getchar();
		return -1;
	}
	if (!CryptImportKey(hProv, out, len, NULL, CRYPT_EXPORTABLE, &hKey1))
	{
		DWORD err = GetLastError();
		std::cout << "导入密钥失败：" << err << std::endl;
		getchar();
		return -1;
	}
	delete[]out;
	out = NULL;
	if (!CryptStringToBinaryA(pubkey, strlen(pubkey), CRYPT_STRING_BASE64_ANY, NULL, &len, NULL, NULL))
	{
		DWORD err = GetLastError();
		std::cout << "得到解码长度失败2：" << err << std::endl;
		getchar();
		return -1;
	}
	out = new BYTE[len + 1];
	if (!CryptStringToBinaryA(pubkey, strlen(pubkey), CRYPT_STRING_BASE64_ANY, out, &len, NULL, NULL))
	{
		delete[]out;
		DWORD err = GetLastError();
		std::cout << "base64解码失败2：" << err << std::endl;
		getchar();
		return -1;
	}
	CERT_PUBLIC_KEY_INFO *pInfo = NULL;
	DWORD len2 = 0;
	if (!CryptDecodeObjectEx((X509_ASN_ENCODING | PKCS_7_ASN_ENCODING), X509_PUBLIC_KEY_INFO, out, len, CRYPT_DECODE_ALLOC_FLAG, NULL, &pInfo, &len2))
	{
		LocalFree(pInfo);
		DWORD err = GetLastError();
		std::cout << "公钥解码失败：" << err << std::endl;
		getchar();
		return -1;
	}
	if (!CryptImportPublicKeyInfo(hProv, X509_ASN_ENCODING, pInfo, &hKey2))
	{
		LocalFree(pInfo);
		DWORD err = GetLastError();
		std::cout << "导入公钥失败：" << err << std::endl;
		getchar();
		return -1;
	}
	LocalFree(pInfo);
	pInfo = NULL;

	const char* msg = "123456789";
	HCRYPTKEY hHash = NULL;
	if (!CryptCreateHash(hProv, CALG_SHA_256, 0, 0, &hHash))
	{
		DWORD err = GetLastError();
		std::cout << "创建hash失败：" << err << std::endl;
		getchar();
		return -1;
	}
	if (!CryptHashData(hHash, (BYTE*)msg, strlen(msg), 0))
	{
		DWORD err = GetLastError();
		std::cout << "hash失败：" << err << std::endl;
		getchar();
		return -1;
	}
	if (!CryptSignHash(hHash, AT_SIGNATURE, NULL, 0, NULL, &len))
	{
		DWORD err = GetLastError();
		std::cout << "得到签名长度失败：" << err << std::endl;
		getchar();
		return -1;
	}
	out = new BYTE[len + 1];
	if (!CryptSignHash(hHash, AT_SIGNATURE, NULL, 0, out, &len))
	{
		delete[]out;
		DWORD err = GetLastError();
		std::cout << "签名失败：" << err << std::endl;
		getchar();
		return -1;
	}
	CryptDestroyHash(hHash);
	hHash = NULL;
	if (!CryptCreateHash(hProv, CALG_SHA_256, 0, 0, &hHash))
	{
		DWORD err = GetLastError();
		std::cout << "创建hash失败2：" << err << std::endl;
		getchar();
		return -1;
	}
	if (!CryptHashData(hHash, (BYTE*)msg, strlen(msg), 0))
	{
		DWORD err = GetLastError();
		std::cout << "hash失败2：" << err << std::endl;
		getchar();
		return -1;
	}
	if (CryptVerifySignature(hHash, out, len, hKey2, NULL, 0))
	{
		std::cout << "成功" << std::endl;
	}
	else
	{
		std::cout << "失败" << std::endl;
	}
	getchar();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
