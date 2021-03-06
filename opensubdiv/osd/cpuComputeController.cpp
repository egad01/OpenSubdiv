//
//     Copyright (C) Pixar. All rights reserved.
//
//     This license governs use of the accompanying software. If you
//     use the software, you accept this license. If you do not accept
//     the license, do not use the software.
//
//     1. Definitions
//     The terms "reproduce," "reproduction," "derivative works," and
//     "distribution" have the same meaning here as under U.S.
//     copyright law.  A "contribution" is the original software, or
//     any additions or changes to the software.
//     A "contributor" is any person or entity that distributes its
//     contribution under this license.
//     "Licensed patents" are a contributor's patent claims that read
//     directly on its contribution.
//
//     2. Grant of Rights
//     (A) Copyright Grant- Subject to the terms of this license,
//     including the license conditions and limitations in section 3,
//     each contributor grants you a non-exclusive, worldwide,
//     royalty-free copyright license to reproduce its contribution,
//     prepare derivative works of its contribution, and distribute
//     its contribution or any derivative works that you create.
//     (B) Patent Grant- Subject to the terms of this license,
//     including the license conditions and limitations in section 3,
//     each contributor grants you a non-exclusive, worldwide,
//     royalty-free license under its licensed patents to make, have
//     made, use, sell, offer for sale, import, and/or otherwise
//     dispose of its contribution in the software or derivative works
//     of the contribution in the software.
//
//     3. Conditions and Limitations
//     (A) No Trademark License- This license does not grant you
//     rights to use any contributor's name, logo, or trademarks.
//     (B) If you bring a patent claim against any contributor over
//     patents that you claim are infringed by the software, your
//     patent license from such contributor to the software ends
//     automatically.
//     (C) If you distribute any portion of the software, you must
//     retain all copyright, patent, trademark, and attribution
//     notices that are present in the software.
//     (D) If you distribute any portion of the software in source
//     code form, you may do so only under this license by including a
//     complete copy of this license with your distribution. If you
//     distribute any portion of the software in compiled or object
//     code form, you may only do so under a license that complies
//     with this license.
//     (E) The software is licensed "as-is." You bear the risk of
//     using it. The contributors give no express warranties,
//     guarantees or conditions. You may have additional consumer
//     rights under your local laws which this license cannot change.
//     To the extent permitted under your local laws, the contributors
//     exclude the implied warranties of merchantability, fitness for
//     a particular purpose and non-infringement.
//

#include "../osd/cpuComputeContext.h"
#include "../osd/cpuComputeController.h"
#include "../osd/cpuKernel.h"

namespace OpenSubdiv {
namespace OPENSUBDIV_VERSION {


OsdCpuComputeController::OsdCpuComputeController() {
}

OsdCpuComputeController::~OsdCpuComputeController() {
}

void
OsdCpuComputeController::ApplyBilinearFaceVerticesKernel(
    FarKernelBatch const &batch, void * clientdata) const {

    OsdCpuComputeContext * context =
        static_cast<OsdCpuComputeContext*>(clientdata);
    assert(context);

    OsdCpuComputeFace(
        context->GetVertexDescriptor(),
        context->GetCurrentVertexBuffer(),
        context->GetCurrentVaryingBuffer(),
        (const int*)context->GetTable(FarSubdivisionTables<OsdVertex>::F_IT)->GetBuffer(),
        (const int*)context->GetTable(FarSubdivisionTables<OsdVertex>::F_ITa)->GetBuffer(),
        batch.GetVertexOffset(), batch.GetTableOffset(), batch.GetStart(), batch.GetEnd());
}

void
OsdCpuComputeController::ApplyBilinearEdgeVerticesKernel(
    FarKernelBatch const &batch, void * clientdata) const {

    OsdCpuComputeContext * context =
        static_cast<OsdCpuComputeContext*>(clientdata);
    assert(context);

    OsdCpuComputeBilinearEdge(
        context->GetVertexDescriptor(),
        context->GetCurrentVertexBuffer(),
        context->GetCurrentVaryingBuffer(),
        (const int*)context->GetTable(FarSubdivisionTables<OsdVertex>::E_IT)->GetBuffer(),
        batch.GetVertexOffset(), batch.GetTableOffset(), batch.GetStart(), batch.GetEnd());
}

void
OsdCpuComputeController::ApplyBilinearVertexVerticesKernel(
    FarKernelBatch const &batch, void * clientdata) const {

    OsdCpuComputeContext * context =
        static_cast<OsdCpuComputeContext*>(clientdata);
    assert(context);

    OsdCpuComputeBilinearVertex(
        context->GetVertexDescriptor(),
        context->GetCurrentVertexBuffer(),
        context->GetCurrentVaryingBuffer(),
        (const int*)context->GetTable(FarSubdivisionTables<OsdVertex>::V_ITa)->GetBuffer(),
        batch.GetVertexOffset(), batch.GetTableOffset(), batch.GetStart(), batch.GetEnd());
}

void
OsdCpuComputeController::ApplyCatmarkFaceVerticesKernel(
    FarKernelBatch const &batch, void * clientdata) const {

    OsdCpuComputeContext * context =
        static_cast<OsdCpuComputeContext*>(clientdata);
    assert(context);

    OsdCpuComputeFace(
        context->GetVertexDescriptor(),
        context->GetCurrentVertexBuffer(),
        context->GetCurrentVaryingBuffer(),
        (const int*)context->GetTable(FarSubdivisionTables<OsdVertex>::F_IT)->GetBuffer(),
        (const int*)context->GetTable(FarSubdivisionTables<OsdVertex>::F_ITa)->GetBuffer(),
        batch.GetVertexOffset(), batch.GetTableOffset(), batch.GetStart(), batch.GetEnd());
}

void
OsdCpuComputeController::ApplyCatmarkEdgeVerticesKernel(
    FarKernelBatch const &batch, void * clientdata) const {

    OsdCpuComputeContext * context =
        static_cast<OsdCpuComputeContext*>(clientdata);
    assert(context);

    OsdCpuComputeEdge(
        context->GetVertexDescriptor(),
        context->GetCurrentVertexBuffer(),
        context->GetCurrentVaryingBuffer(),
        (const int*)context->GetTable(FarSubdivisionTables<OsdVertex>::E_IT)->GetBuffer(),
        (const float*)context->GetTable(FarSubdivisionTables<OsdVertex>::E_W)->GetBuffer(),
        batch.GetVertexOffset(), batch.GetTableOffset(), batch.GetStart(), batch.GetEnd());
}

void
OsdCpuComputeController::ApplyCatmarkVertexVerticesKernelB(
    FarKernelBatch const &batch, void * clientdata) const {

    OsdCpuComputeContext * context =
        static_cast<OsdCpuComputeContext*>(clientdata);
    assert(context);

    OsdCpuComputeVertexB(
        context->GetVertexDescriptor(),
        context->GetCurrentVertexBuffer(),
        context->GetCurrentVaryingBuffer(),
        (const int*)context->GetTable(FarSubdivisionTables<OsdVertex>::V_ITa)->GetBuffer(),
        (const int*)context->GetTable(FarSubdivisionTables<OsdVertex>::V_IT)->GetBuffer(),
        (const float*)context->GetTable(FarSubdivisionTables<OsdVertex>::V_W)->GetBuffer(),
        batch.GetVertexOffset(), batch.GetTableOffset(), batch.GetStart(), batch.GetEnd());
}

void
OsdCpuComputeController::ApplyCatmarkVertexVerticesKernelA1(
    FarKernelBatch const &batch, void * clientdata) const {

    OsdCpuComputeContext * context =
        static_cast<OsdCpuComputeContext*>(clientdata);
    assert(context);

    OsdCpuComputeVertexA(
        context->GetVertexDescriptor(),
        context->GetCurrentVertexBuffer(),
        context->GetCurrentVaryingBuffer(),
        (const int*)context->GetTable(FarSubdivisionTables<OsdVertex>::V_ITa)->GetBuffer(),
        (const float*)context->GetTable(FarSubdivisionTables<OsdVertex>::V_W)->GetBuffer(),
        batch.GetVertexOffset(), batch.GetTableOffset(), batch.GetStart(), batch.GetEnd(), false);
}

void
OsdCpuComputeController::ApplyCatmarkVertexVerticesKernelA2(
    FarKernelBatch const &batch, void * clientdata) const {

    OsdCpuComputeContext * context =
        static_cast<OsdCpuComputeContext*>(clientdata);
    assert(context);

    OsdCpuComputeVertexA(
        context->GetVertexDescriptor(),
        context->GetCurrentVertexBuffer(),
        context->GetCurrentVaryingBuffer(),
        (const int*)context->GetTable(FarSubdivisionTables<OsdVertex>::V_ITa)->GetBuffer(),
        (const float*)context->GetTable(FarSubdivisionTables<OsdVertex>::V_W)->GetBuffer(),
        batch.GetVertexOffset(), batch.GetTableOffset(), batch.GetStart(), batch.GetEnd(), true);
}

void
OsdCpuComputeController::ApplyLoopEdgeVerticesKernel(
    FarKernelBatch const &batch, void * clientdata) const {

    OsdCpuComputeContext * context =
        static_cast<OsdCpuComputeContext*>(clientdata);
    assert(context);

    OsdCpuComputeEdge(
        context->GetVertexDescriptor(),
        context->GetCurrentVertexBuffer(),
        context->GetCurrentVaryingBuffer(),
        (const int*)context->GetTable(FarSubdivisionTables<OsdVertex>::E_IT)->GetBuffer(),
        (const float*)context->GetTable(FarSubdivisionTables<OsdVertex>::E_W)->GetBuffer(),
        batch.GetVertexOffset(), batch.GetTableOffset(), batch.GetStart(), batch.GetEnd());
}

void
OsdCpuComputeController::ApplyLoopVertexVerticesKernelB(
    FarKernelBatch const &batch, void * clientdata) const {

    OsdCpuComputeContext * context =
        static_cast<OsdCpuComputeContext*>(clientdata);
    assert(context);

    OsdCpuComputeLoopVertexB(
        context->GetVertexDescriptor(),
        context->GetCurrentVertexBuffer(),
        context->GetCurrentVaryingBuffer(),
        (const int*)context->GetTable(FarSubdivisionTables<OsdVertex>::V_ITa)->GetBuffer(),
        (const int*)context->GetTable(FarSubdivisionTables<OsdVertex>::V_IT)->GetBuffer(),
        (const float*)context->GetTable(FarSubdivisionTables<OsdVertex>::V_W)->GetBuffer(),
        batch.GetVertexOffset(), batch.GetTableOffset(), batch.GetStart(), batch.GetEnd());
}

void
OsdCpuComputeController::ApplyLoopVertexVerticesKernelA1(
    FarKernelBatch const &batch, void * clientdata) const {

    OsdCpuComputeContext * context =
        static_cast<OsdCpuComputeContext*>(clientdata);
    assert(context);

    OsdCpuComputeVertexA(
        context->GetVertexDescriptor(),
        context->GetCurrentVertexBuffer(),
        context->GetCurrentVaryingBuffer(),
        (const int*)context->GetTable(FarSubdivisionTables<OsdVertex>::V_ITa)->GetBuffer(),
        (const float*)context->GetTable(FarSubdivisionTables<OsdVertex>::V_W)->GetBuffer(),
        batch.GetVertexOffset(), batch.GetTableOffset(), batch.GetStart(), batch.GetEnd(), false);
}

void
OsdCpuComputeController::ApplyLoopVertexVerticesKernelA2(
    FarKernelBatch const &batch, void * clientdata) const {

    OsdCpuComputeContext * context =
        static_cast<OsdCpuComputeContext*>(clientdata);
    assert(context);

    OsdCpuComputeVertexA(
        context->GetVertexDescriptor(),
        context->GetCurrentVertexBuffer(),
        context->GetCurrentVaryingBuffer(),
        (const int*)context->GetTable(FarSubdivisionTables<OsdVertex>::V_ITa)->GetBuffer(),
        (const float*)context->GetTable(FarSubdivisionTables<OsdVertex>::V_W)->GetBuffer(),
        batch.GetVertexOffset(), batch.GetTableOffset(), batch.GetStart(), batch.GetEnd(), true);
}

void
OsdCpuComputeController::ApplyVertexEdits(
    FarKernelBatch const &batch, void * clientdata) const {

    OsdCpuComputeContext * context =
        static_cast<OsdCpuComputeContext*>(clientdata);
    assert(context);

    const OsdCpuHEditTable *edit = context->GetEditTable(batch.GetTableIndex());
    assert(edit);

    const OsdCpuTable * primvarIndices = edit->GetPrimvarIndices();
    const OsdCpuTable * editValues = edit->GetEditValues();

    if (edit->GetOperation() == FarVertexEdit::Add) {
        OsdCpuEditVertexAdd(context->GetVertexDescriptor(),
                            context->GetCurrentVertexBuffer(),
                            edit->GetPrimvarOffset(),
                            edit->GetPrimvarWidth(),
                            batch.GetVertexOffset(), 
                            batch.GetTableOffset(), 
                            batch.GetStart(), 
                            batch.GetEnd(),
                            static_cast<unsigned int*>(primvarIndices->GetBuffer()),
                            static_cast<float*>(editValues->GetBuffer()));
    } else if (edit->GetOperation() == FarVertexEdit::Set) {
        OsdCpuEditVertexSet(context->GetVertexDescriptor(),
                            context->GetCurrentVertexBuffer(),
                            edit->GetPrimvarOffset(),
                            edit->GetPrimvarWidth(),
                            batch.GetVertexOffset(), 
                            batch.GetTableOffset(), 
                            batch.GetStart(), 
                            batch.GetEnd(),
                            static_cast<unsigned int*>(primvarIndices->GetBuffer()),
                            static_cast<float*>(editValues->GetBuffer()));
    }
}

void
OsdCpuComputeController::Synchronize() {
}

}  // end namespace OPENSUBDIV_VERSION
}  // end namespace OpenSubdiv
