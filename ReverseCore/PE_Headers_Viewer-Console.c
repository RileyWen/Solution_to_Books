#include <stdio.h>
#include <windows.h>
#include <winnt.h>
#include <time.h>
HANDLE MyOpenFile(char *szFile){
    HANDLE hFile = CreateFile(szFile, GENERIC_READ, FILE_SHARE_READ,
                              NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile==INVALID_HANDLE_VALUE){
        printf("CreateFile error!");
        exit(-1);
    }
    return hFile;
}
int main(int argc,char *argv[]){
    if (argc!=2){
        printf("Parameter amount not correct!");
        exit(-1);
    }

    HANDLE hFile = MyOpenFile(argv[1]);
    //DWORD FileSize = GetFileSize(hFile, NULL);
    char buf[26];
    DWORD dwByteRead = 0;
    errno_t err;
    LONG filePointer;

    //Read IMAGE_DOS_HEADER
    struct _IMAGE_DOS_HEADER IMAGE_DOS_HEADER;
    filePointer = SetFilePointer( hFile, sizeof(IMAGE_DOS_HEADER)-sizeof(IMAGE_DOS_HEADER.e_lfanew),
                                0, FILE_BEGIN);
    ReadFile(hFile, &IMAGE_DOS_HEADER.e_lfanew, 4, &dwByteRead, NULL);

    printf("IMAGE_DOS_HEADER:\n");
    printf("\te_lfanew:\t%lX\n", IMAGE_DOS_HEADER.e_lfanew);
    
    //Read IMAGE_NT_HEADERS
    struct tm _gmtime_s;
    struct _IMAGE_NT_HEADERS64 IMAGE_NT_HEADERS;
    filePointer = SetFilePointer( hFile, IMAGE_DOS_HEADER.e_lfanew,
                                 0, FILE_BEGIN);
    ReadFile   (hFile, &IMAGE_NT_HEADERS, sizeof(struct _IMAGE_NT_HEADERS),
                &dwByteRead, NULL);

    //Read IMAGE_NT_HEADERS.Magic
    printf("IMAGE_NT_HEADERS:\n");
    printf("\tSignature:\t%lX\n", IMAGE_NT_HEADERS.Signature);

    //Read IMAGE_NT_HEADERS.IMAGE_FILE_HEADER
    printf("\tIMAGE_FILE_HEADER:\n");
    printf("\t\tMachine:\t\t%hX\n", IMAGE_NT_HEADERS.FileHeader.Machine);
    if (IMAGE_NT_HEADERS.FileHeader.Machine!=0x8664){
        printf("EXE is not 64-bit!\n");
        exit(-1);
    }

    printf("\t\tNumberOfSections:\t%hd(Dec)\n", IMAGE_NT_HEADERS.FileHeader.NumberOfSections);
    time_t lt = IMAGE_NT_HEADERS.FileHeader.TimeDateStamp;
    err = gmtime_s(&_gmtime_s, &lt);
    asctime_s(buf, 26, &_gmtime_s);
    printf("\t\tTimeDateStamp:\t\t%s", buf);
    printf("\t\tPointerToSymbolTable:\t%lX\n",IMAGE_NT_HEADERS.FileHeader.PointerToSymbolTable);
    printf("\t\tNumberOfSymbols:\t%lX\n", IMAGE_NT_HEADERS.FileHeader.NumberOfSymbols);
    printf("\t\tSizeOfOptionalHeader:\t%hX\n", IMAGE_NT_HEADERS.FileHeader.SizeOfOptionalHeader);
    printf("\t\tCharacteristics:\t%hX\n", IMAGE_NT_HEADERS.FileHeader.Characteristics);

    
    //Read IMAGE_NT_HEADERS.IMAGE_OPTIONAL_HEADER64
    printf("\tIMAGE_OPTIONAL_HEADER64:\n");
    printf("\t\tMagic:\t\t\t%hX\n",IMAGE_NT_HEADERS.OptionalHeader.Magic);
    printf("\t\tAddressOfEntryPoint:\t%lX\n",IMAGE_NT_HEADERS.OptionalHeader.AddressOfEntryPoint);
    printf("\t\tImageBase:\t\t%llX\n", IMAGE_NT_HEADERS.OptionalHeader.ImageBase);
    printf("\t\tSectionAlignment:\t%lX\n", IMAGE_NT_HEADERS.OptionalHeader.SectionAlignment);
    printf("\t\tFileAlignment:\t\t%lX\n", IMAGE_NT_HEADERS.OptionalHeader.FileAlignment);
    printf("\t\tSizeOfImage:\t\t%lX\n", IMAGE_NT_HEADERS.OptionalHeader.SizeOfImage);
    printf("\t\tSizeOfHeaders:\t\t%lX\n", IMAGE_NT_HEADERS.OptionalHeader.SizeOfHeaders);
    printf("\t\tSubsystem:\t\t%hX\n", IMAGE_NT_HEADERS.OptionalHeader.Subsystem);
    printf("\t\tNumberOfRvaAndSizes:\t%lX\n", IMAGE_NT_HEADERS.OptionalHeader.NumberOfRvaAndSizes);

    //Read IMAGE_NT_HEADERS.OptionalHeader.DataDirectory[]
    char* SECTION_HEADER_NAME[]={
        "EXPORT Directory",         //0
        "IMPORT Directory",         //1
        "RESOURCE Directory",       //2
        "EXCEPTION Directory",      //3
        "SECURITY Directory",       //4
        "BASERELOC Directory",      //5
        "DEBUG Directory",          //6
        "COPYRIGHT Directory",      //7
        "GLOBALPTR Directory",      //8
        "TLS Directory",            //9
        "LOAD_CONFIG Directory",    //10
        "BOUND_IMPORT Directory",   //11
        "IAT Directory",            //12
        "DELAY_IMPORT Directory",   //13
        "COM_DESCRIPTOR Directory", //14
        "Reserved Directory"        //15
    };

    printf("\t\tDataDirectory[]:\n");
    for (int i = 0; i < IMAGE_NT_HEADERS.OptionalHeader.NumberOfRvaAndSizes;i++){
        printf("\t\t\tDataDirectory[%X]->%s:\n", i, SECTION_HEADER_NAME[i]);
        printf("\t\t\t\tVirtualAddress:%lX\n", IMAGE_NT_HEADERS.OptionalHeader.DataDirectory[i].VirtualAddress);
        printf("\t\t\t\tSize:%lX\n", IMAGE_NT_HEADERS.OptionalHeader.DataDirectory[i].Size);
    }

    //Read Section headers
    int cnt = 0;
    struct _IMAGE_SECTION_HEADER IMAGE_SECTION_HEADER;
    char IMAGE_SECTION_HEADER_ZERO[sizeof(struct _IMAGE_SECTION_HEADER)] = {0};;
    
    filePointer = SetFilePointer(   hFile, filePointer + sizeof(IMAGE_NT_HEADERS64),
                                    0, FILE_BEGIN);
    printf("IMAGE_SECTION_HEADER[]:\n");
    do{
        ReadFile(hFile, &IMAGE_SECTION_HEADER, sizeof(struct _IMAGE_SECTION_HEADER),
                 &dwByteRead, NULL);
        printf("\tIMAGE_SECTION_HEADER[%d]:\n", cnt++);

        printf("\t\tName:\t%s\n", IMAGE_SECTION_HEADER.Name);
        printf("\t\tVirtualSize:\t%lX\n", IMAGE_SECTION_HEADER.Misc.VirtualSize);
        printf("\t\tVirtualAddress:\t%lX\n", IMAGE_SECTION_HEADER.VirtualAddress);
        printf("\t\tSizeOfRawData:\t%lX\n", IMAGE_SECTION_HEADER.SizeOfRawData);
        printf("\t\tPointerToRawData:\t%lX\n", IMAGE_SECTION_HEADER.PointerToRawData);
        printf("\t\tPointerToRelocations:\t%lX\n", IMAGE_SECTION_HEADER.PointerToRelocations);
        printf("\t\tNumberOfLinenumbers:\t%hX\n", IMAGE_SECTION_HEADER.NumberOfLinenumbers);
        printf("\t\tCharacteristics:\t%lX\n", IMAGE_SECTION_HEADER.Characteristics);
    } while (memcmp(IMAGE_SECTION_HEADER_ZERO,&IMAGE_SECTION_HEADER,sizeof(struct _IMAGE_SECTION_HEADER)));

    //read IAT
    filePointer = SetFilePointer(   hFile, filePointer + sizeof(IMAGE_NT_HEADERS64),
                                    0, FILE_BEGIN);

    CloseHandle(hFile);
    printf("%llX", sizeof(struct _IMAGE_IMPORT_DESCRIPTOR));
    return 0;
}
