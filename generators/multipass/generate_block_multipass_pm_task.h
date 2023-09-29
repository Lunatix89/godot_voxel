#ifndef VOXEL_GENERATE_BLOCK_MULTIPASS_PM_TASK_H
#define VOXEL_GENERATE_BLOCK_MULTIPASS_PM_TASK_H

#include "../../util/tasks/threaded_task.h"
#include "voxel_generator_multipass.h"

namespace zylann::voxel {

// Looks up blocks in the map in order to run a pass on a specific block.
// If at least one block isn't found in the map, the task is cancelled.
// If at least one block doesn't fulfills dependency requirements and no task is pending for it, the task is cancelled.
class GenerateBlockMultipassPMTask : public IThreadedTask {
public:
	GenerateBlockMultipassPMTask(Vector3i p_block_position, uint8_t p_block_size, uint8_t p_subpass_index,
			Ref<VoxelGeneratorMultipass> p_generator, TaskPriority p_priority);

	~GenerateBlockMultipassPMTask();

	const char *get_debug_name() const override {
		return "GenerateBlockMultipassPMTask";
	}

	void run(ThreadedTaskContext &ctx) override;

	TaskPriority get_priority() override {
		return _priority;
	}

	// TODO Implement cancellation
	// bool is_cancelled() {}

private:
	Vector3i _block_position;
	uint8_t _block_size;
	uint8_t _subpass_index;
	Ref<VoxelGeneratorMultipass> _generator;
	TaskPriority _priority;
};

} // namespace zylann::voxel

#endif // VOXEL_GENERATE_BLOCK_MULTIPASS_PM_TASK_H