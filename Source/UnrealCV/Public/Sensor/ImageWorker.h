// Weichao @ 2017
#pragma once
#include "ImageUtil.h"

struct FFrameData
{
	TArray<FColor> ImageData; // TODO, this data copy might be very slow
	int Width;
	int Height;
	FString Filename;
	int FrameNumber;
};

/** Use a seperate thread to write image to files */
class FImageWorker : public FRunnable
{
public:
	FImageWorker();

	void Start();

	void SaveFile(const TArray<FColor>& ImageData, const int Width, const int Height, const FString& Filename);

	virtual uint32 Run() override;

	virtual void Stop() override;

	/** Virtual destructor. */
	virtual ~FImageWorker();

private:
	FImageUtil ImageUtil;
	TQueue<FFrameData> PendingData;
	FRunnableThread* Thread;
	bool Stopping;
};