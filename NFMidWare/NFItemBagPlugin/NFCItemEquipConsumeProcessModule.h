// -------------------------------------------------------------------------
//    @FileName			:   NFCItemEquipConsumeProcessModule.h
//    @Author           :   Yu.Tang
//    @Date             :   2016-07-02
//    @Module           :   NFCItemEquipConsumeProcessModule

// -------------------------------------------------------------------------

#ifndef NFC_ITEM_EQUIP_CONSUME_PROCESS_MODULE_H
#define NFC_ITEM_EQUIP_CONSUME_PROCESS_MODULE_H

#include <iostream>
#include "NFComm/NFPluginModule/NFIKernelModule.h"
#include "NFComm/NFPluginModule/NFIPackModule.h"
#include "NFComm/NFPluginModule/NFIElementModule.h"
#include "NFComm/NFPluginModule/NFILogModule.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFIItemModule.h"
#include "NFComm/NFPluginModule/NFIHeroModule.h"
#include "NFComm/NFPluginModule/NFIEquipModule.h"
#include "NFComm/NFPluginModule/NFIItemConsumeProcessModule.h"

class NFCItemEquipConsumeProcessModule
	: public NFIItemConsumeProcessModule
{

public:
	NFCItemEquipConsumeProcessModule(NFIPluginManager* p)
	{
		pPluginManager = p;
	}
	virtual bool Init();
	virtual bool Shut();
	virtual bool Execute();
	virtual bool AfterInit();

	
	virtual int ConsumeLegal(const NFGUID& self, const std::string& strItemID, const NFDataList& targetID);

	
	virtual int ConsumeProcess(const NFGUID& self, const std::string& strItemID, const NFDataList& targetID);

private:
	NFIKernelModule* m_pKernelModule;
	NFILogModule* m_pLogModule;
	NFIPackModule* m_pPackModule;
	NFIElementModule* m_pElementModule;
	NFIItemModule* m_pItemModule;
	NFIHeroModule* m_pHeroModule;
	NFIEquipModule* m_pEquipModule;
};

#endif
