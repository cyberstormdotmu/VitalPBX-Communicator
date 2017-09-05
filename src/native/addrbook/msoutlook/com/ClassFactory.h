/*
 * Jitsi, the OpenSource Java VoIP and Instant Messaging client.
 *
 * Copyright @ 2015 Atlassian Pty Ltd
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef __MSOUTLOOKADDRBOOKCOM_CLASSFACTORY_H
#define __MSOUTLOOKADDRBOOKCOM_CLASSFACTORY_H

#include <Unknwn.h>

/**
 * Represents a base implementation of the <tt>IClassFactory</tt> interface.
 *
 * @author Lyubomir Marinov
 * @author Vincent Lucas
 */
class ClassFactory:
    public IClassFactory
{
    public:
        STDMETHODIMP QueryInterface(REFIID iid, PVOID *obj);
        STDMETHODIMP_(ULONG) AddRef();
        STDMETHODIMP_(ULONG) Release();

        STDMETHOD(LockServer)(BOOL lock);

        HRESULT registerClassObject();
        HRESULT revokeClassObject();

        ClassFactory(REFCLSID clsid);

    protected:
        virtual ~ClassFactory();

    private:
        const CLSID _clsid;
        DWORD _registration;
        ULONG _refCount;
};

#endif
